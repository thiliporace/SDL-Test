//
//  Subject.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 08/01/25.
//

#include <stdio.h>
#include "Subject.hpp"

Subject::Subject(Observer* observer){
    addObserver(observer);
}

Subject::~Subject(){
    observers.clear();
}

void Subject::addObserver(Observer* observer){
    observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer){
    //Retorna o iterador do objeto, se o objeto nao for encontrado ele retorna observers.end()
    auto iterator = std::find(observers.begin(), observers.end(), observer);
    
    //Apenas aceita o objeto se tiver sido encontrado
    if (iterator != observers.end()){
        observers.erase(iterator);
    }
}

void Subject::notify(EventEnum event, const Shape& shape){
    for(auto observer : observers){
        observer->onNotify(event, shape);
    }
}
