//
//  MoveCommand.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#ifndef MoveCommand_hpp
#define MoveCommand_hpp

#include <stdio.h>
#include "CommandProtocol.h"
#include "ShapeMovement.hpp"

class MoveCommand: public CommandProtocol{
private:
    int xSpeed, ySpeed;
    ShapeMovement& shapeMovement;
public:
    MoveCommand(int xSpeed, int ySpeed, ShapeMovement& shapeMovement);

    virtual void execute(Shape& shape) override;
};

#endif /* MoveCommand_hpp */
