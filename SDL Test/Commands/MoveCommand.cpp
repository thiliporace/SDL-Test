//
//  MoveCommand.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#include "MoveCommand.hpp"
#include "Shape.hpp"

MoveCommand::MoveCommand(int xSpeed, int ySpeed):xSpeed(xSpeed), ySpeed(ySpeed) {}

void MoveCommand::execute(Shape& shape){
    shape.move(xSpeed, ySpeed);
}
