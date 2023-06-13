#include "game.h"
#include "data.h"

void Game::startGame() {
    playerPosX = screenWidth / 2;
    playerPosY = screenHeight / 2;

    liveCount = 3;
    scoreCount = 0;
    ballCount = 3;
    ballsOnScreen = 3;
    enemyCount = 1;

    isBallPosGenerated = false;
    isEnemyPosGenerated = false;
    isGameOver = false;
}