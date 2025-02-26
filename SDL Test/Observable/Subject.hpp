//
//  Subject.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 08/01/25.
//

#ifndef Subject_hpp
#define Subject_hpp

#include <stdio.h>
#include <vector>
#include "Observer.hpp"

class Subject {
private:
    std::vector <Observer*> observers;
    
public:
    Subject(Observer* observer);
    
    ~Subject();
    
    void notify(EventEnum event, const Shape& shape);
    
    void addObserver(Observer* observer);
    
    void removeObserver(Observer* observer);
};

#endif /* Subject_hpp */
