//
//  ScoreObserver.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 08/01/25.
//

#include "ScoreObserver.hpp"

ScoreObserver::ScoreObserver(int& leftScore, int& rightScore, Label& leftScoreObject, Label& rightScoreObject): leftScore(leftScore), rightScore(rightScore), leftScoreObject(leftScoreObject), rightScoreObject(rightScoreObject) {}

void ScoreObserver::onNotify(EventEnum event, const Shape& shape){
    switch (event) {
        case LEFT_SIDE_SCORE:
            leftScore++;
            leftScoreObject.setValue(leftScore);
            break;
        case RIGHT_SIDE_SCORE:
            rightScore++;
            rightScoreObject.setValue(rightScore);

            break;
        default:
            break;
    }
}
