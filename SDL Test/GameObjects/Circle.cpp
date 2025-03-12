//
//  Circle.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#include "Circle.hpp"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <sstream>

#include "Shape.hpp"
#include "Label.hpp"
#include "ShapePool.hpp"

Circle::Circle(int xPos,int yPos, ShapePool& shapePool, std::string tag) {
    shapePool.create(xPos, yPos, circleWidth, circleHeight, circleAssetName, tag);
};

