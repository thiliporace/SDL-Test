//
//  Shape.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#include "Shape.hpp"
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>

#include "SdlManager.hpp"
#include "ShapeAssetManager.hpp"

using namespace std;

Shape::Shape() {}

void Shape::init(int xPos, int yPos, float width, float height, char* assetName, std::string tag){
    
    startXPos = xPos;
    startYPos = yPos;
    this->tag = tag;
    
    SdlManager* sdlManager = SdlManager::getInstance();
    
    ShapeAssetManager* shapeAssetManager = ShapeAssetManager::getInstance(sdlManager->getRenderer());
    
    shapeTexture = shapeAssetManager->getAsset(assetName);
    
    SDL_QueryTexture(shapeTexture, NULL, NULL, &pos.w, &pos.h); //Conecta textura com posicao
    
    setStartPosition(xPos, yPos, width, height);
}

const void Shape::setStartPosition(int& xPos, int& yPos, float width, float height) {
    pos.x = xPos;
    pos.y = yPos;
    
    pos.w *= width;
    pos.h *= height;
};

Shape::~Shape(){
    if (shapeTexture) {
        SDL_DestroyTexture(shapeTexture);
        shapeTexture = nullptr;
    }
}

void Shape::move(int x, int y){
    if (x == 0){
        pos.y += y;
    }
    else if (y == 0){
        pos.x += x;
    }
    else{
        pos.x += x;
        pos.y += y;
    }
    
}
