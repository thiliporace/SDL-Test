//
//  InputManager.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#include "InputManager.hpp"
#include <SDL2/SDL.h>

void InputManager::handleInput(SDL_Event& event){
    //api pra tecla pressionada
    switch(event.key.keysym.scancode) {
        case SDL_SCANCODE_W:
            if (key_w && shapeKeyW){
                key_w->execute(*shapeKeyW);
                break;
            }
            break;
        
        case SDL_SCANCODE_S:
            if (key_s && shapeKeyS){
                key_s->execute(*shapeKeyS);
                break;
            }
            break;
        
        case SDL_SCANCODE_UP:
            if (key_up_arrow && shapeKeyUpArrow){
                key_up_arrow->execute(*shapeKeyUpArrow);
                break;
            }
            break;
            
        case SDL_SCANCODE_DOWN:
            if (key_down_arrow && shapeKeyDownArrow){
                key_down_arrow->execute(*shapeKeyDownArrow);
                break;
            }
            break;
            
        default:
            break;
    }
    
}

void InputManager::setKey(char key, CommandProtocol* command, Shape* shape) {
    switch (key) {
        case 'W':
            key_w = command;
            shapeKeyW = shape;
            break;
        case 'S':
            key_s = command;
            shapeKeyS = shape;
            break;
        case 'U':
            key_up_arrow = command;
            shapeKeyUpArrow = shape;
            break;
        case 'D':
            key_down_arrow = command;
            shapeKeyDownArrow = shape;
            break;
        default:
            break;
    }
}
