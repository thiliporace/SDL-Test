//
//  ShapePool.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/02/25.
//

#include "ShapePool.hpp"

void ShapePool::create(int xPos, int yPos, float width, float height, char *assetName, std::string tag){
    for (int i = 0; i < POOL_SIZE; i++){
        if(shapes[i].shapeTexture == NULL){
            shapes[i].init(xPos, yPos, width, height, assetName, tag);
            return;
        }
    }
}


Shape& ShapePool::getShapeFromPool(std::string tag){
    for (int i = 0; i < POOL_SIZE; i++) {
        if (shapes[i].getTag() == tag){
            return shapes[i];
        }
    }
    throw std::runtime_error("nao achou shape com mesma tag");
}
