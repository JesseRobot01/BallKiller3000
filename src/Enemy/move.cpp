#include <iostream>
#include "../enemyAi.h"
#include "../data.h"
#include "../utils.h"
#include "../pos.h"
#include "../ball.h"

void EnemyAi::generateMove() {
    for (int enemy = 0; enemy < enemyCount; ++enemy) {
        if (Pos::isPosInScreen(enemyPos[enemy])) {

            int moveType;
            raylib::Vector2 moveTo;
            raylib::Vector2 pushBall;
            float moveDistance;


            // 1,2 = neutral move, 3,4,5 = ai move, 6 = rotation, 7,8 failed
            moveType = Utils::random(1, 8);

            // there are no AI moves for the neutral one, so set the move to neutral;
            if (enemyPreference[enemy] == 1 && (moveType == 3 || moveType == 4 || moveType == 5)) {
                moveType = 1;
            }


            if (moveType == 1 || moveType == 2) {
                moveTo = Vector2(Utils::random(-30, 30), Utils::random(-30, 30));
                EnemyAi::move(enemy, moveTo);
                pushBall = moveTo;
            }


            if (moveType == 3 || moveType == 4 || moveType == 5) {
                int nearest;
                if (enemyPreference[enemy] == 2) {
                    nearest = Utils::getNearest(Data::ball, enemyPos[enemy]);

                    moveDistance = Utils::random(1, 30);
                    EnemyAi::moveTo(enemy, ballPos[nearest], moveDistance);
                    pushBall = enemyPos[enemy].MoveTowards(ballPos[nearest], moveDistance)- enemyPos[enemy];
                }
                if (enemyPreference[enemy] == 3) {
                    moveDistance = Utils::random(-1, 15);
                    EnemyAi::moveTo(enemy, playerPos, moveDistance);
                    pushBall = enemyPos[enemy].MoveTowards(playerPos, moveDistance)- enemyPos[enemy];

                }
                if (enemyPreference[enemy] == 4) {
                    nearest = Utils::getNearest(Data::enemy, enemyPos[enemy], enemy);

                    moveDistance = Utils::random(1, 30);
                    EnemyAi::moveTo(enemy, enemyPos[nearest], moveDistance);
                    pushBall = enemyPos[enemy].MoveTowards(enemyPos[nearest], moveDistance) - enemyPos[enemy];

                }

            }

            if (moveType == 6) {
                float oldSizeX;
                float oldSizeY;
                oldSizeX = enemySize[enemy].x;
                oldSizeY = enemySize[enemy].y;

                enemySize[enemy].x = oldSizeY;
                enemySize[enemy].y = oldSizeX;

            }
            for (int b = 0; b < ballCount; ++b) {
                if (Utils::haveCollision(Data::enemy, Data::ball, enemy, b)) {
                    Ball::push(b, pushBall);
                }
            }
        }
        Utils::checkAllCollisions(Data::player, Data::enemy);


    }
}

void EnemyAi::move(int enemyNum, raylib::Vector2 distance) {
    if (Pos::isPosInScreen(enemyPos[enemyNum] + distance))
        enemyPos[enemyNum] += distance;
}

void EnemyAi::moveTo(int enemyNum, raylib::Vector2 targetPos, float maxSteps) {
    if (Pos::isPosInScreen(targetPos)) {
        if (Pos::isPosInScreen(enemyPos[enemyNum].MoveTowards(targetPos, maxSteps))) {
            enemyPos[enemyNum] = enemyPos[enemyNum].MoveTowards(targetPos, maxSteps);
        }
    }
}