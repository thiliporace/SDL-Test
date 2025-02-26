//
//  ShapePool.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/02/25.
//

#ifndef ShapePool_hpp
#define ShapePool_hpp

#include <stdio.h>
#include "Shape.hpp"

class ShapePool{
public:
    void create(int xPos, int yPos, float width, float height, char* assetName, std::string tag);
    
    Shape& getShapeFromPool(std::string tag);

private:
    static const int POOL_SIZE = 5;
    Shape shapes[POOL_SIZE];
};

#endif /* ShapePool_hpp */
