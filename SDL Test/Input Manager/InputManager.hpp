//
//  InputManager.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <stdio.h>
#include "CommandProtocol.h"

class InputManager {
private:
    Shape* shapeKeyW;
    Shape* shapeKeyS;
    Shape* shapeKeyUpArrow;
    Shape* shapeKeyDownArrow;
    
    CommandProtocol* key_w;
    CommandProtocol* key_s;
    CommandProtocol* key_up_arrow;
    CommandProtocol* key_down_arrow;
public:
    void handleInput(SDL_Event& event);
    
    void setKey(char key, CommandProtocol* command, Shape* shape);
};

#endif /* InputManager_hpp */
