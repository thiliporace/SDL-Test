//
//  ShapeMovement.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#include "ShapeMovement.hpp"
#include "Shape.hpp"

void ShapeMovement::move(Shape& shape, int x, int y){
    if (x == shape.pos.x){
        shape.pos.y += y;
    }
    else if (y == shape.pos.y){
        shape.pos.x += x;
    }
    else{
        shape.pos.x += x;
        shape.pos.y += y;
    }
    
}
