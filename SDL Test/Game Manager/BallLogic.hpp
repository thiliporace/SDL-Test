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
#include "ShapeMovement.hpp"
#include "MoveCommand.hpp"
#include "Subject.hpp"
#include "ScoreObserver.hpp"

class BallLogic {
private:
    int xSpeed;
    int ySpeed;
    Subject scoreSubject;

public:
    BallLogic(ScoreObserver* scoreObserver);
    void calculateBall(Circle& ball, Rectangle& leftRectangle, Rectangle& rightRectangle, Score& leftScoreObject, Score& rightScoreObject, bool& gameStarted, int& rightScore, int& leftScore);
    void restartBall(Circle& circle, int xPos, int yPos);

private:
    bool checkCollision(SDL_Rect a, SDL_Rect b);
};


#endif /* BallLogic_hpp */
