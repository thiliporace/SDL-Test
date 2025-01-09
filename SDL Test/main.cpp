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

int main(){
    //Pega mesma instancia de SDLManager que foi usada ate agora
    SdlManager* sdlManager = SdlManager::getInstance();
    
    bool gameStarted = true;

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
    
    BallLogic ballLogic(&scoreObserver);
    
    ShapeMovement shapeMovement;
    
    InputManager inputManager;
    
    inputManager.setKey('W', new MoveCommand(0,-50,shapeMovement), &leftRectangle);
    inputManager.setKey('S', new MoveCommand(0,50,shapeMovement), &leftRectangle);
    inputManager.setKey('U', new MoveCommand(0,-50,shapeMovement), &rightRectangle);
    inputManager.setKey('D', new MoveCommand(0,50,shapeMovement), &rightRectangle);
    
    while (!quit){
        // events handling
        while(SDL_PollEvent(&event)){
            
            switch (event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                
                case SDL_KEYDOWN:
                    inputManager.handleInput(event);
            }
            
        }
        
        SDL_Renderer* renderer = sdlManager->getRenderer();
        
        // rendering
        SDL_RenderClear(renderer); //Limpa a tela
        SDL_RenderCopy(renderer, circle.shapeTexture, NULL, &circle.pos);
        SDL_RenderCopy(renderer, leftRectangle.shapeTexture, NULL, &leftRectangle.pos);
        SDL_RenderCopy(renderer, rightRectangle.shapeTexture, NULL, &rightRectangle.pos);
        SDL_RenderCopy(renderer, leftScoreObject.textTexture, NULL, &leftScoreObject.rect);
        SDL_RenderCopy(renderer, rightScoreObject.textTexture, NULL, &rightScoreObject.rect);
        
        SDL_RenderPresent(renderer);
        
        //calcula pra 60 fps
        SDL_Delay(1000/60);
        
        // update
        if (gameStarted){
            ballLogic.calculateBall(&scoreObserver, circle, leftRectangle, rightRectangle, leftScoreObject, rightScoreObject, gameStarted, rightScore, leftScore);
        }
        else{
            ballLogic.restartBall(circle, 400, 400);
            gameStarted = true;
        }
        
    }
    
    SDL_Quit();
    return 0;
}
