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
#include "Score.hpp"

class ScoreObserver: public Observer{
private:
    int& leftScore;
    int& rightScore;
    Score& leftScoreObject;
    Score& rightScoreObject;
public:
    ScoreObserver(int& leftScore, int& rightScore, Score& leftScoreObject, Score& rightScoreObject);
    void onNotify(EventEnum event, const Shape& shape) override;
};

#endif /* ScoreObserver_hpp */
