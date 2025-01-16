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
    bool gameStarted;
    Subject scoreSubject;
    Circle& ball;
    Rectangle& leftRectangle;
    Rectangle& rightRectangle;
    
    bool checkCollision(SDL_Rect a, SDL_Rect b);

public:
    ~BallLogic() {}
    BallLogic(ScoreObserver* scoreObserver, Circle& ball, Rectangle& leftRectangle, Rectangle& rightRectangle);
    virtual void calculateBall();
    virtual void restartBall(int xPos, int yPos);
    //Cada objeto que vai ser atualizado precisa da sua implementacao de update()
    virtual void update();
};


#endif /* BallLogic_hpp */
