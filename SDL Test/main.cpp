//
//  main.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 18/12/24.
//

#include "main.hpp"
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <sstream>
#include <cmath>

#include "SdlManager.hpp"
#include "Shape.hpp"
#include "Label.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "MoveCommand.hpp"
#include "InputManager.hpp"
#include "BallLogic.hpp"
#include "ShapePool.hpp"

using namespace std;

const float MS_PER_UPDATE = 0.016;

float getCurrentTime() {
    return SDL_GetTicks() / 1000.0f;
}

int main(){
    //Pega mesma instancia de SDLManager que foi usada ate agora
    SdlManager* sdlManager = SdlManager::getInstance();

    //Inicializar variaveis do score
    int leftScore = 0;
    int rightScore = 0;
    
    //Calculo de fps
    float fps = 0;
    
    //Inicializar pool de objetos
    ShapePool shapePool = ShapePool();
    
    //Ao criar os objetos, eles automaticamente inicializam objetos vazios na pool
    Circle circle(400,400,shapePool,"circle1");
    Rectangle leftRectangle(50, 300,shapePool,"rectangle1");
    Rectangle rightRectangle(740, 300,shapePool,"rectangle2");
    
    //Se voce tentar usar apenas os objetos em cima, nao vai funcionar pois estao sendo criados na pool por fora :/
    Shape& circleObject = shapePool.getShapeFromPool("circle1");
    Shape& leftRectangleObject = shapePool.getShapeFromPool("rectangle1");
    Shape& rightRectangleObject = shapePool.getShapeFromPool("rectangle2");
    
    //Cria os objetos score e o texto do fps
    Label rightScoreObject(700, 150, rightScore, "Score: ");
    Label leftScoreObject(50, 150,leftScore, "Score: ");
    
    rightScoreObject.setValue(rightScore);
    leftScoreObject.setValue(leftScore);
    
    SDL_Event event;
    bool quit = false;
    
    ScoreObserver scoreObserver = ScoreObserver(leftScore, rightScore, leftScoreObject, rightScoreObject);
    
    BallLogic ballLogic(&scoreObserver, circleObject, leftRectangleObject, rightRectangleObject);
    
    InputManager inputManager;
    
    inputManager.setKey('W', new MoveCommand(0,-50), &leftRectangleObject);
    inputManager.setKey('S', new MoveCommand(0,50), &leftRectangleObject);
    inputManager.setKey('U', new MoveCommand(0,-50), &rightRectangleObject);
    inputManager.setKey('D', new MoveCommand(0,50), &rightRectangleObject);
    
    //Calculo usado no Game Loop pra garantir que PCs mais rapidos e mais lentos tenham a mesma experiencia de jogo
    double previous = getCurrentTime();
    double lag = 0.0;
    
    SDL_Renderer* renderer = sdlManager->getRenderer();
    
    //Variaveis pra medir FPS
    bool fixedFrameRate = false;
    const int TARGET_FPS = 144;
    const float TARGET_FRAME_TIME = 1000.0f / TARGET_FPS;
    
    float fpsSum = 0.0f;
    int frameCount = 0;
    
    while (!quit){
        Uint64 startFrame = SDL_GetPerformanceCounter();
        
        //No começo de cada frame, pegamos quanto tempo real passou desde o ultimo turno do game loop. Isso é a quantidade de tempo de jogo que precisamos simular para que o agora do jogo acompanhe o agora do jogador.
        double current = getCurrentTime();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;
        
        /// EVENTS HANDLING
        while(SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    inputManager.handleInput(event);
            }
        }
        
        /// UPDATE
        //Botar esses if dentro do update da muuuito cache miss 💔 tem que resolver isso no futuro
        if (fixedFrameRate){
            ballLogic.update(elapsed,true);
        }
        else{
            while(lag >= MS_PER_UPDATE){
                //Logica do jogo encapsulada no proprio objeto, de acordo com padrão Update
                ballLogic.update(elapsed,false);
                lag -= MS_PER_UPDATE;
            }
        }
        
        /// RENDERING
        SDL_RenderClear(renderer); //Limpa a tela
        SDL_RenderCopy(renderer, circleObject.shapeTexture, NULL, &circleObject.pos);
        SDL_RenderCopy(renderer, leftRectangleObject.shapeTexture, NULL, &leftRectangleObject.pos);
        SDL_RenderCopy(renderer, rightRectangleObject.shapeTexture, NULL, &rightRectangleObject.pos);
        SDL_RenderCopy(renderer, leftScoreObject.textTexture, NULL, &leftScoreObject.rect);
        SDL_RenderCopy(renderer, rightScoreObject.textTexture, NULL, &rightScoreObject.rect);
        
        Uint64 endFrame = SDL_GetPerformanceCounter();
        float frameTime = (endFrame - startFrame) * 1000.0f / SDL_GetPerformanceFrequency();

        if (frameTime < TARGET_FRAME_TIME && fixedFrameRate) {
            SDL_Delay(TARGET_FRAME_TIME - frameTime);
        }

        endFrame = SDL_GetPerformanceCounter();
        frameTime = (endFrame - startFrame) * 1000.0f / SDL_GetPerformanceFrequency();
        float fps = 1000.0f / std::max(frameTime, 0.001f);
        
        fpsSum += fps;
        frameCount++;
        
        
        cout << "FPS: " << fps << "Avg FPS: " << (fpsSum/frameCount) << endl;
        
        //Apresenta janela
        SDL_RenderPresent(renderer);
        
    }
    
    SDL_Quit();
    return 0;
}
