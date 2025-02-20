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
    std::string tag;
    int startXPos {};
    int startYPos {};
    int zPos = 1;
public:
    
    std::string getTag() { return tag; };
    
    SDL_Surface *sprite;

    SDL_Texture *shapeTexture;
    
    SDL_Rect pos; //Deixa a gente poder controlar sua posicao
    
    //Construtor padrão da classe
    Shape();
    
    void init(int xPos, int yPos, float width, float height, char* assetName, std::string tag);
    
    const void setStartPosition(int& xPos, int& yPos, float width, float height);
    
    void move(int x, int y);
    
    ~Shape();
};

#endif /* Shape_hpp */
