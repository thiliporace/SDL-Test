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
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "MoveCommand.hpp"
#include "InputManager.hpp"
#include "BallLogic.hpp"

using namespace std;

float MS_PER_UPDATE = 0.016;

float getCurrentTime() {
    return SDL_GetTicks() / 1000.0f;
}

int main(){
    //Pega mesma instancia de SDLManager que foi usada ate agora
    SdlManager* sdlManager = SdlManager::getInstance();

    int leftScore = 0;
    int rightScore = 0;
    
    Circle circle(400,400);
    
    Rectangle leftRectangle(50, 300);
    Rectangle rightRectangle(740, 300);
    
    Score rightScoreObject(700, 150, rightScore);
    Score leftScoreObject(50, 150,leftScore);
    
    rightScoreObject.setScore(rightScore);
    leftScoreObject.setScore(leftScore);
    
    SDL_Event event;
    bool quit = false;
    
    ScoreObserver scoreObserver = ScoreObserver(leftScore, rightScore, leftScoreObject, rightScoreObject);
    
    BallLogic ballLogic(&scoreObserver, circle, leftRectangle, rightRectangle);
    
    InputManager inputManager;
    
    inputManager.setKey('W', new MoveCommand(0,-50), &leftRectangle);
    inputManager.setKey('S', new MoveCommand(0,50), &leftRectangle);
    inputManager.setKey('U', new MoveCommand(0,-50), &rightRectangle);
    inputManager.setKey('D', new MoveCommand(0,50), &rightRectangle);
    
    double previous = getCurrentTime();
    double lag = 0.0;
    
    while (!quit){
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
        
        /// RENDERING
        SDL_Renderer* renderer = sdlManager->getRenderer();
        
        SDL_RenderClear(renderer); //Limpa a tela
        SDL_RenderCopy(renderer, circle.shapeTexture, NULL, &circle.pos);
        SDL_RenderCopy(renderer, leftRectangle.shapeTexture, NULL, &leftRectangle.pos);
        SDL_RenderCopy(renderer, rightRectangle.shapeTexture, NULL, &rightRectangle.pos);
        SDL_RenderCopy(renderer, leftScoreObject.textTexture, NULL, &leftScoreObject.rect);
        SDL_RenderCopy(renderer, rightScoreObject.textTexture, NULL, &rightScoreObject.rect);
        
        SDL_RenderPresent(renderer);
        
        /// UPDATE
        while(lag >= MS_PER_UPDATE){
            //Logica do jogo encapsulada no proprio objeto, de acordo com protocolo Update
            ballLogic.update();
            lag -= MS_PER_UPDATE;
        }

    }
    
    SDL_Quit();
    return 0;
}
