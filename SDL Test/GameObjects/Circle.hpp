//
//  Circle.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <sstream>

#include "Shape.hpp"
#include "Score.hpp"

class Circle: public Shape{
private:
    
    //Usa static constexpr pra conseguir entrar na lista de inicializacao do construtor
    static constexpr char* circleAssetName = "circle.png";
    static constexpr float circleWidth = 0.15;
    static constexpr float circleHeight = 0.15;
    
public:
    Circle(int xPos,int yPos);
};

#endif /* Circle_hpp */
