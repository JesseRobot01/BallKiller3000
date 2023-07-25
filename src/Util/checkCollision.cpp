#include <iostream>
#include "../utils.h"
#include "../data.h"
#include "../ball.h"
#include "../enemyAi.h"


// the loops to check collision with another object
void Utils::checkAllCollision(Data::Types target, Data::Types with) {
    if (target == Data::player) {
        if (with == Data::ball) {
            for (int B = 0; B < ballCount; ++B) {
                Utils::checkBallTouchPlayer(target, with, 0, B);
            }


        }
        if (with == Data::enemy) {
            for (int e = 0; e < enemyCount; ++e) {
                Utils::checkBallTouchPlayer(target, with, 0, e);
            }
        }
    }

    if (target == Data::ball) {
        if (with == Data::player) {
            for (int B = 0; B < ballCount; ++B) {
                Utils::checkBallTouchPlayer(with, target, 0, B);
            }


        }
        if (with == Data::enemy) {
            for (int e = 0; e < enemyCount; ++e) {
                for (int b = 0; e < ballCount; ++e) {

                    Utils::checkBallTouchPlayer(with, target, e, b);

                }
            }
        }

    }
}

// the code thad actually checks and executes on collision
void Utils::checkBallTouchPlayer(Data::Types target, Data::Types with, int targetNum, int withNum) {
    if (target == Data::player) {
        if (with == Data::ball) {
            if (playerPos.CheckCollision(ballPos[withNum], 45)) Ball::kill(withNum);
        }
        if (with == Data::enemy) {
            if (playerPos.CheckCollision(
                    Rectangle(enemyPos[withNum].x - 15, enemyPos[withNum].y - 15, enemySize[withNum].x + 30,
                              enemySize[withNum].y + 30)))

                EnemyAi::killPlayer(withNum);
        }
    }

    if (target == Data::enemy) {
        if (with == Data::ball) {
            if (ballPos[withNum].CheckCollision(
                    Rectangle(enemyPos[targetNum].x - 15, enemyPos[targetNum].y - 15, enemySize[targetNum].x + 30,
                              enemySize[targetNum].y + 30))) {}
        }
    }
}

