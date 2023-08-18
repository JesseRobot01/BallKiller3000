#include "../enemyAi.h"
#include "../gameHandler.h"

void EnemyAi::killPlayer(int enemyNum, int playerNum) {
    if (!isGameOver) {
        lives[playerNum]--;
        enemies[enemyNum].pos = Vector2(-1000, -1000);
        enemiesInScreen--;
        GameHandler::endGame();
    }
}