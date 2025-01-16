//
//  Shape.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>

class Shape {
private:
    int startXPos {};
    int startYPos {};
    int zPos = 1;
public:
    
    SDL_Surface *sprite;

    SDL_Texture *shapeTexture;
    
    SDL_Rect pos; //Deixa a gente poder controlar sua posicao
    
    Shape(int xPos, int yPos, float width, float height, char* assetName);
    
    //Construtor padrão da classe
    Shape();
    
    const void setStartPosition(int& xPos, int& yPos, float width, float height);
    
    void move(int x, int y);
    
    ~Shape();
};

#endif /* Shape_hpp */
