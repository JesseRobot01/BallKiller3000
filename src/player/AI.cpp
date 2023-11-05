#include "../player.h"
#include "../data.h"

void Player::generateAIMove() {
    raylib::Vector2 moveTo;

    // check if a ball or an enemy is closer
    int closestBallNum = getNearestBall();
    int closestEnemyNum = getNearestEnemy();

    if (closestEnemyNum != -1) {
        if (pos.Distance(ball[closestBallNum].pos) >= pos.Distance(enemy[closestEnemyNum].pos)) {
            if (enemy[closestEnemyNum].pos.CheckCollision(pos, 200)) {
                moveTo = pos.MoveTowards(enemy[closestEnemyNum].pos, speed) - pos;
                move(-moveTo);
                return;
            }
        }
    }
    moveTo = pos.MoveTowards(ball[closestBallNum].pos, speed) - pos;

    move(moveTo);
}