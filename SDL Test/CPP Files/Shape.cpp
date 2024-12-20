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

using namespace std;

Shape::Shape(int xPos, int yPos, float width, float height, char* assetName): startXPos(xPos), startYPos(yPos){
    
    SdlManager* sdlManager = SdlManager::getInstance();
    
    sprite = IMG_Load(assetName);
    
    if (!sprite){
        cout << "Error Surface: " << SDL_GetError() << endl;
        return;
    }
    
    shapeTexture = SDL_CreateTextureFromSurface(sdlManager->getRenderer(), sprite);
    
    if (!shapeTexture) {
        cout << "Error Texture: " << SDL_GetError() << endl;
        return;
    }
    
    SDL_FreeSurface(sprite); //Limpa memoria
    
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
    SDL_DestroyTexture(shapeTexture);
}
