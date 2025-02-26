//
//  Rectangle.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(int xPos, int yPos, ShapePool& shapePool, std::string tag) {
    shapePool.create(xPos, yPos, rectangleWidth, rectangleHeight, rectangleAssetName, tag);
};
