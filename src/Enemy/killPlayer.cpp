#include "../enemyAi.h"
#include "../gameHandler.h"

void Enemy::killPlayer(int playerNum) {
    if (!isGameOver) {
        lives[playerNum]--;
        pos = Vector2(-1000, -1000);
        enemiesInScreen--;
        GameHandler::endGame();
    }
}