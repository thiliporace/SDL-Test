//
//  ScoreObserver.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 08/01/25.
//

#include "ScoreObserver.hpp"

ScoreObserver::ScoreObserver(int& leftScore, int& rightScore, Score& leftScoreObject, Score& rightScoreObject): leftScore(leftScore), rightScore(rightScore), leftScoreObject(leftScoreObject), rightScoreObject(rightScoreObject) {}

void ScoreObserver::onNotify(EventEnum event, const Shape& shape){
    switch (event) {
        case LEFT_SIDE_SCORE:
            leftScore++;
            leftScoreObject.setScore(leftScore);
            break;
        case RIGHT_SIDE_SCORE:
            rightScore++;
            rightScoreObject.setScore(rightScore);

            break;
        default:
            break;
    }
}
