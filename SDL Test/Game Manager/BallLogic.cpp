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

BallLogic::BallLogic(ScoreObserver* scoreObserver, Circle& ball, Rectangle& leftRectangle, Rectangle& rightRectangle) : xSpeed(6), ySpeed(6), scoreSubject(scoreObserver), ball(ball), leftRectangle(leftRectangle), rightRectangle(rightRectangle) {}

bool BallLogic::checkCollision(SDL_Rect a, SDL_Rect b) {
    int leftA = a.x;
    int rightA = a.x + a.w;
    int topA = a.y;
    int bottomA = a.y + a.h;

    int leftB = b.x;
    int rightB = b.x + b.w;
    int topB = b.y;
    int bottomB = b.y + b.h;

    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB) {
        return false;
    }

    return true;
}

void BallLogic::calculateBall() {
    
    // Lógica de colisão com os retângulos (paddles)
    if (checkCollision(ball.pos, leftRectangle.pos) || checkCollision(ball.pos, rightRectangle.pos)) {
        xSpeed = -xSpeed;
    }

    // Lógica de colisão com as bordas superiores e inferiores
    if (ball.pos.y <= 10 || ball.pos.y >= 580) {
        ySpeed = -ySpeed;
    }

    // Se a bola sair pela esquerda
    if (ball.pos.x <= -10) {
        gameStarted = false;
        scoreSubject.notify(RIGHT_SIDE_SCORE,ball);
    }

    // Se a bola sair pela direita
    if (ball.pos.x >= 810) {
        gameStarted = false;
        scoreSubject.notify(LEFT_SIDE_SCORE,ball);
    }
}

void BallLogic::restartBall(int xPos, int yPos) {
    ball.pos.x = xPos;
    ball.pos.y = yPos;
}

void BallLogic::update(){
    if (gameStarted){
        calculateBall();
        
        // Movendo a bola
        MoveCommand moveBall(xSpeed, ySpeed);
        moveBall.execute(ball);
    }
    else{
        restartBall(400, 400);
        gameStarted = true;
    }
}
