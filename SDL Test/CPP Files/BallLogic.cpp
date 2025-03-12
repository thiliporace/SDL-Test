//
//  BallLogic.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#include "BallLogic.hpp"

#include "Shape.hpp"
#include "Score.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <sstream>

bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    
    
        if( bottomA <= topB )
        {
            return false;
        }

        if( topA >= bottomB )
        {
            return false;
        }

        if( rightA <= leftB )
        {
            return false;
        }

        if( leftA >= rightB )
        {
            return false;
        }

        
        return true;
    }


void calculateBall(Circle& ball, Rectangle& leftRectangle, Rectangle& rightRectangle, Score& leftScoreObject, Score& rightScoreObject, bool& gameStarted, int& rightScore, int& leftScore, bool fixedUpdate, float deltaTime) {
    static int xSpeed = 6;
    static int ySpeed = 6;
    
    int speedMultiplier = 0;
    
    if(!fixedUpdate){
        // Nao era pra estar assim aqui, era pra estar 1, mas por quesitos de teste vou mudar
        speedMultiplier = 140;
    }
    else{
        speedMultiplier = 70;
    }

    if (checkCollision(ball.pos, leftRectangle.pos) || checkCollision(ball.pos, rightRectangle.pos)) {
        xSpeed = -xSpeed;
    }

    if (ball.pos.y <= 10 || ball.pos.y >= 580) {
        ySpeed = -ySpeed;
    }

    if (ball.pos.x <= -10) {
        gameStarted = false;
        rightScore++;
        rightScoreObject.setScore(rightScore);
    }

    if (ball.pos.x >= 810) {
        gameStarted = false;
        leftScore++;
        leftScoreObject.setScore(leftScore);
    }

    ball.pos.x += xSpeed * speedMultiplier * deltaTime;
    ball.pos.y += ySpeed * speedMultiplier * deltaTime;
}


void restartBall(Circle& circle, int xPos, int yPos) {
    circle.pos.x = xPos;
    circle.pos.y = yPos;
}
