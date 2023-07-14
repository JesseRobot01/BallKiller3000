#include "../enemy.h"
#include "../data.h"
#include "../player.h"


void Enemy::checkPlayerKill() {
    // I use the same one as the ball one but with some little tweaks
    for (int i = 0; i < enemyCount; ++i) {
        if (playerPosX >= enemyPosX[i] && playerPosX <= enemyPosX[i] + 60 &&
            playerPosY >= enemyPosY[i] && playerPosY <= enemyPosY[i] + 30) {
            enemyPosX[i] = -100;
            enemyPosY[i] = -100;
            Player::kill();
        }
    }
}