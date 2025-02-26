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
    //Associa cada tecla a um sprite
    Shape* shapeKeyW;
    Shape* shapeKeyS;
    Shape* shapeKeyUpArrow;
    Shape* shapeKeyDownArrow;
    
    //Associa cada tecla a uma ação
    CommandProtocol* key_w;
    CommandProtocol* key_s;
    CommandProtocol* key_up_arrow;
    CommandProtocol* key_down_arrow;
public:
    //Função que reconhece o input e chama o execute de cada ação
    void handleInput(SDL_Event& event);
    
    //Função usada para associar uma tecla com um comando e um sprite
    void setKey(char key, CommandProtocol* command, Shape* shape);
};

#endif /* InputManager_hpp */
