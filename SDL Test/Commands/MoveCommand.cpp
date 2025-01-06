//
//  MoveCommand.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#include "MoveCommand.hpp"
#include "Shape.hpp"

MoveCommand::MoveCommand(int ySpeed, ShapeMovement& shapeMovement): ySpeed(ySpeed), shapeMovement(shapeMovement) {}

void MoveCommand::execute(Shape& shape){
    shapeMovement.move(shape, shape.pos.x, ySpeed);
}
