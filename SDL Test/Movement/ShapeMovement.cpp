//
//  ShapeMovement.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#include "ShapeMovement.hpp"
#include "Shape.hpp"

void ShapeMovement::move(Shape& shape, int x, int y){
    if (x == 0){
        shape.pos.y += y;
    }
    else if (y == 0){
        shape.pos.x += x;
    }
    else{
        shape.pos.x += x;
        shape.pos.y += y;
    }
    
}
