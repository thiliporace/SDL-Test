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
    
    while (!quit){
        // events handling
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
            calculateBall(circle, leftRectangle, rightRectangle, leftScoreObject, rightScoreObject, gameStarted, rightScore, leftScore);
        }
        else{
            restartBall(circle, 400, 400);
            gameStarted = true;
        }
        
    }
    
    SDL_Quit();
    return 0;
}
