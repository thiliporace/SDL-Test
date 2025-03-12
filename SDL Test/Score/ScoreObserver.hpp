//
//  ScoreObserver.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 08/01/25.
//

#ifndef ScoreObserver_hpp
#define ScoreObserver_hpp

#include <stdio.h>
#include "Observer.hpp"
#include "Label.hpp"

class ScoreObserver: public Observer{
private:
    int& leftScore;
    int& rightScore;
    Label& leftScoreObject;
    Label& rightScoreObject;
public:
    ScoreObserver(int& leftScore, int& rightScore, Label& leftScoreObject, Label& rightScoreObject);
    void onNotify(EventEnum event, const Shape& shape) override;
};

#endif /* ScoreObserver_hpp */
