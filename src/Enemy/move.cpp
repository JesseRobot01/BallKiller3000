#include "../enemyAi.h"
#include "../utils.h"
#include "../pos.h"
#include "../ball.h"

void EnemyAi::generateMove() {
    for (int enemy = 0; enemy < enemyCount; ++enemy) {
        if (Pos::isPosInScreen(enemies[enemy].pos)) {

            int moveType;
            raylib::Vector2 moveTo;
            raylib::Vector2 pushBall;
            float moveDistance;


            // 1,2 = neutral move, 3,4,5 = ai move, 6 = rotation, 7,8 failed
            moveType = Utils::random(1, 8);


            // there are no AI moves for the neutral one, so set the move to neutral;
            if (enemies[enemy].preference == 1 && (moveType == 3 || moveType == 4 || moveType == 5)) {
                moveType = 1;
            }


            if (moveType == 1 || moveType == 2) {
                moveTo = Vector2(Utils::randomFloat(-30, 30), Utils::randomFloat(-30, 30));
                enemies[enemy].move(moveTo);
                pushBall = moveTo;
            }


            if (moveType == 3 || moveType == 4 || moveType == 5) {
                int nearest;
                if (enemies[enemy].preference == 2) {
                    nearest = Utils::getNearest(Data::ball, enemies[enemy].pos);

                    moveDistance = Utils::randomFloat(1, 30);
                    enemies[enemy].moveTo(ballPos[nearest], moveDistance);
                    pushBall = enemies[enemy].pos.MoveTowards(ballPos[nearest], moveDistance) - enemies[enemy].pos;
                }
                if (enemies[enemy].preference == 3) {
                    if (!isGameOver) {
                        nearest = Utils::getNearest(Data::player, enemies[enemy].pos, enemy);
                        moveDistance = Utils::randomFloat(-1, 15);
                        enemies[enemy].moveTo(playerPos[nearest], moveDistance);
                        pushBall =
                                enemies[enemy].pos.MoveTowards(playerPos[nearest], moveDistance) - enemies[enemy].pos;

                    }
                }
                if (enemies[enemy].preference == 4) {
                    nearest = Utils::getNearest(Data::enemy, enemies[enemy].pos, enemy);
                    if (nearest == -1) return;

                    moveDistance = Utils::randomFloat(1, 30);
                    enemies[enemy].moveTo(enemies[nearest].pos, moveDistance);
                    pushBall = enemies[enemy].pos.MoveTowards(enemies[nearest].pos, moveDistance) - enemies[enemy].pos;

                }

            }

            if (moveType == 6) {
                float oldSizeX;
                float oldSizeY;
                oldSizeX = enemies[enemy].size.x;
                oldSizeY = enemies[enemy].size.y;

                enemies[enemy].size.x = oldSizeY;
                enemies[enemy].size.y = oldSizeX;

            }
            for (int b = 0; b < ballCount; ++b) {
                if (Utils::hasCollision(Data::enemy, Data::ball, enemy, b)) {
                    Ball::push(b, pushBall);
                }
            }
        }
        Utils::checkAllCollisions(Data::player, Data::enemy);


    }
}

void Enemy::move(raylib::Vector2 distance) {
    if (!Pos::isClippingOutsideScreen(Data::enemy, pos + distance, enemyNumber))
        pos += distance;
}

void Enemy::moveTo(raylib::Vector2 targetPos, float maxSteps) {
    if (Pos::isPosInScreen(targetPos)) {
        if (!Pos::isClippingOutsideScreen(Data::enemy, pos.MoveTowards(targetPos, maxSteps),
                                          enemyNumber)) {
            pos = pos.MoveTowards(targetPos, maxSteps);
        }
    }
}