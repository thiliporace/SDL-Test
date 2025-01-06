//
//  Command.h
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#ifndef CommandProtocol_h
#define CommandProtocol_h

#include "Shape.hpp"

//O input do jogo irá utilizar o Design Pattern Command
class CommandProtocol{
public:
    virtual ~CommandProtocol() {}
    virtual void execute(Shape& shape) = 0;
};

#endif /* Command_h */
