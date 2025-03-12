//
//  BallLogic.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#ifndef BallLogic_hpp
#define BallLogic_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <sstream>

#include "Shape.hpp"
#include "Score.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

bool checkCollision( SDL_Rect a, SDL_Rect b );


void calculateBall(Circle& ball, Rectangle& leftRectangle, Rectangle& rightRectangle, Score& leftScoreObject, Score& rightScoreObject, bool& gameStarted, int& rightScore, int& leftScore, bool fixedUpdate, float deltaTime);


void restartBall(Circle& circle, int xPos, int yPos);

#endif /* BallLogic_hpp */
