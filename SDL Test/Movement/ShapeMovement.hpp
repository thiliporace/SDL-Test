//
//  ShapeMovement.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#ifndef ShapeMovement_hpp
#define ShapeMovement_hpp

#include <stdio.h>
#include "Shape.hpp"

class ShapeMovement{
public:
    void move(Shape& shape, int x, int y);
};

#endif /* ShapeMovement_hpp */
