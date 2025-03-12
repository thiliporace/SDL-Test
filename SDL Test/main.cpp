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

#include "SdlManager.hpp"
#include "Shape.hpp"
#include "Score.hpp"
#include "BallLogic.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

using namespace std;

const float MS_PER_UPDATE = 0.016;

float getCurrentTime() {
    return SDL_GetTicks() / 1000.0f;
}

int main(){
    //Pega mesma instancia de SDLManager que foi usada ate agora
    SdlManager* sdlManager = SdlManager::getInstance();
    
    bool gameStarted = true;

    int leftScore = 0;
    int rightScore = 0;
    
    Circle circle(400,400);
    
    Rectangle leftRectangle(50, 300);
    Rectangle rightRectangle(740, 300);
    
    Score leftScoreObject(50, 150,leftScore);
    Score rightScoreObject(700, 150, rightScore);
    
    SDL_Event event;
    bool quit = false;
    
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
        
        /// events handling
        while(SDL_PollEvent(&event)){
            
            switch (event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                
                case SDL_KEYDOWN:
                    //api pra tecla pressionada
                    switch(event.key.keysym.scancode) {
                        case SDL_SCANCODE_W:
                            if (leftRectangle.pos.y > 45){
                                leftRectangle.pos.y -= 50;
                            }
                            break;
                        
                        case SDL_SCANCODE_S:
                            if (leftRectangle.pos.y < 545){
                                leftRectangle.pos.y += 50;
                            }
                            break;
                        
                        case SDL_SCANCODE_UP:
                            if (rightRectangle.pos.y > 45){
                                rightRectangle.pos.y -= 50;
                            }
                            break;
                            
                        case SDL_SCANCODE_DOWN:
                            if (rightRectangle.pos.y < 545){
                                rightRectangle.pos.y += 50;
                            }
                            break;
                            
                        default:
                            break;
                    }
            }
            
        }
        
        /// update
        if (fixedFrameRate){
            if (gameStarted){
                calculateBall(circle, leftRectangle, rightRectangle, leftScoreObject, rightScoreObject, gameStarted, rightScore, leftScore, true, elapsed);
            }
            else{
                restartBall(circle, 400, 400);
                gameStarted = true;
            }
        }
        else{
            while(lag >= MS_PER_UPDATE){
                //Logica do jogo encapsulada no proprio objeto, de acordo com padrão Update
                if (gameStarted){
                    calculateBall(circle, leftRectangle, rightRectangle, leftScoreObject, rightScoreObject, gameStarted, rightScore, leftScore, false, elapsed);
                    lag -= MS_PER_UPDATE;
                }
                else{
                    restartBall(circle, 400, 400);
                    gameStarted = true;
                }
            }
        }
        
        /// rendering
        SDL_RenderClear(renderer); //Limpa a tela
        SDL_RenderCopy(renderer, circle.shapeTexture, NULL, &circle.pos);
        SDL_RenderCopy(renderer, leftRectangle.shapeTexture, NULL, &leftRectangle.pos);
        SDL_RenderCopy(renderer, rightRectangle.shapeTexture, NULL, &rightRectangle.pos);
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
        
        SDL_RenderPresent(renderer);
        
    }
    
    SDL_Quit();
    return 0;
}
