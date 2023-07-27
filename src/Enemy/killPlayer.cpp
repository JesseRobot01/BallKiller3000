#include "../enemyAi.h"
#include "../data.h"
#include "../gameHandler.h"

void EnemyAi::killPlayer(int enemyNum) {
    if (!isGameOver) {
        lives--;
        enemyPos[enemyNum] = Vector2(-1000, -1000);

        GameHandler::endGame();
    }
}