#include "../enemyAi.h"
#include "../gameHandler.h"

void EnemyAi::killPlayer(int enemyNum, int playerNum) {
    if (!isGameOver) {
        if(lives[playerNum] > 0)
        lives[playerNum]--;
        enemyPos[enemyNum] = Vector2(-1000, -1000);
        enemiesInScreen--;
        GameHandler::endGame();
    }
}