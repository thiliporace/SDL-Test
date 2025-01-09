//
//  Observer.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 08/01/25.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>
#include "EventEnum.h"
#include "Shape.hpp"

class Observer{
public:
    virtual ~Observer() {}
    virtual void onNotify(EventEnum event, const Shape& shape) = 0;
};

#endif /* Observer_hpp */
