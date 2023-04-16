#include <random>
#include <iostream>
#include "enemy.h"
#include "data.h"
#include "player.h"
#include "balls.h"

void Enemy::checkPlayerKill() {
    // I use the same one as the ball one but with some little tweaks
    Player player;
    for (int i = 0; i < enemyCount; ++i) {
        if (playerPosX >= enemyPosX[i] && playerPosX <= enemyPosX[i] + 60 &&
            playerPosY >= enemyPosY[i] && playerPosY <= enemyPosY[i] + 30) {
            enemyPosX[i] = -100;
            enemyPosY[i] = -100;
            player.kill();
        }
    };
}

void Enemy::move() {
    for (int i = 0; i < enemyCount; ++i) {
        int moveDirection;
        int moveCounter;

        moveDirection = rand() % (4 - 0 + 1) + 0;
        moveCounter = rand() % (30 - 0 + 1) + 0;

        if (enemyPosX[i] > -30 && enemyPosX[i] < screenWidth + 30 &&
            enemyPosY[i] > 0 - 30 && enemyPosY[i] < screenHeight + 30) {
            if (moveDirection == 1) {
                if (enemyPosX[i] + moveCounter <= screenWidth) { enemyPosX[i] += moveCounter; }
            }
            if (moveDirection == 2) {
                if (enemyPosX[i] - moveCounter >= 0) { enemyPosX[i] -= moveCounter; }
            }
            if (moveDirection == 3) {
                if (enemyPosY[i] + moveCounter <= screenHeight) { enemyPosY[i] += moveCounter; }
            }
            if (moveDirection == 4) {
                if (enemyPosY[i] - moveCounter >= 0) { enemyPosY[i] -= moveCounter; }
            }

            // checks if an enemy is in inside a ball, if yes, push the ball
            // this part is stolen (again)
            for (int b = 0; b < ballCount; ++b) {
                if (ballPosX[b] >= enemyPosX[i] && ballPosX[b] <= enemyPosX[i] + 60 &&
                    ballPosY[b] >= enemyPosY[i] && ballPosY[b] <= enemyPosY[i] + 30) {
                    Balls ball;
                    switch (moveDirection) {
                        case 1:
                            ball.push(b, moveCounter, 'x');
                            break;
                        case 2:
                            ball.push(b, -moveCounter, 'x');
                            break;
                        case 3:
                            ball.push(b, moveCounter, 'Y');
                            break;
                        case 4:
                            ball.push(b, -moveCounter, 'Y');
                            break;
                    }
                }
            };
        }
    }
}