#include <iostream>
#include "../enemy.h"
#include "../utils.h"

void Enemy::generateMove() {
    if (isDead) return; // no need if he's ded

    int moveType;

    // 1,2 = neutral move, 3,4,5 = ai move, 6 = rotation, 7,8 failed
    moveType = Utils::random(1, 8);

    switch (moveType) {
        case 1:
        case 2:
            generateNeutralMove();
            break;
            // AI move switcher
        case 3:
        case 4:
        case 5:
            switch (enemyAI) {
                case neutral:
                    generateNeutralMove();
                    break;
                case ballPreference:
                    generateBallFindMove();
                    break;
                case enemyPreference:
                    generateEnemyFindMove();
                    break;
                case playerPreference:
                    generatePlayerFindMove();
                    break;
            }
            break;

        case 6:
            rotate();
            break;
        case 7:
        case 8:
            return;
        default:
            std::cout << "INFO: How did we get here?\n";
    }

}

void Enemy::generateNeutralMove() {
    move(Vector2(Utils::random(-speed, speed), Utils::random(-speed, speed)));
}

void Enemy::generateBallFindMove() {
    int nearestBall = getNearestBall();
    if (nearestBall == -1) return; // depression

    float moveDistance = Utils::randomFloat(1, speed);
    move(pos.MoveTowards(ball[nearestBall].pos, moveDistance) - pos);
}

void Enemy::generateEnemyFindMove() {
    if (enemiesInScreen == 1) return; // depression
    int nearestEnemy = getNearestEnemy();
    float moveDistance = Utils::randomFloat(1, speed);
    move(pos.MoveTowards(enemy[nearestEnemy].pos, moveDistance) - pos);
}

void Enemy::generatePlayerFindMove() {
    int nearestPlayer = getNearestPlayer();
    if (nearestPlayer == -1) return; // safeguard, think this will never happen. but to make sure.
    float moveDistance = Utils::randomFloat(1, speed);
    move(pos.MoveTowards(player[nearestPlayer].pos, moveDistance) - pos);
}

void Enemy::rotate() {
    Vector2 oldSize;
    oldSize = size;

    size.x = oldSize.y;
    size.y = oldSize.x;

    for (int b = 0; b < ballCount; ++b) {
        if (hasCollision(ball[b])) {
            if (oldSize.y > oldSize.x)
                ball[b].move(Vector2(0, -30));
            else ball[b].move(Vector2(-30, 0));
        }
    }
}

void Enemy::move(Vector2 moveTo, bool isGettingPushed) {
    if (isInScreen(pos + moveTo)) {
        pos += moveTo;
        for (int b = 0; b < ballCount; ++b) {
            if (hasCollision(ball[b])) ball[b].move(moveTo);
        }
        for (int p = 0; p < playerCount; ++p) {
            if (hasCollision(player[p])) {
                player[p].move(moveTo); // move the player

                if (!player[p].isDead) player[p].lives--;
                if (player[p].lives == 0) player[p].isDead = true;
                else {
                    isDead = true;
                }

            }
        }
        if (!isGettingPushed) {
            for (int e = 0; e < enemyCount; ++e) {
                if (hasCollision(enemy[e])) {
                    enemy[e].move(moveTo, true);
                }
            }
        }
    }
}

