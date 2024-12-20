//
//  Rectangle.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <sstream>

#include "SdlManager.hpp"
#include "Shape.hpp"

class Rectangle: public Shape{
private:
    //Usa static constexpr pra conseguir entrar na lista de inicializacao do construtor
    static constexpr char* rectangleAssetName = "rectangle.png";
    static constexpr float rectangleWidth = 0.15;
    static constexpr float rectangleHeight = 0.15;
    
public:
    Rectangle(int xPos, int yPos);
};

#endif /* Rectangle_hpp */
