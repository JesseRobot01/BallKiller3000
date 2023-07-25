#include "../gameHandler.h"
#include "../data.h"
#include "../pos.h"
#include "../enemyAi.h"

void GameHandler::checkLevelUp(bool firstTimeRun) {
    if (ballsInScreen <= 0 || firstTimeRun) {
        delete[] ballPos;
        delete[] enemyPos;
        delete[] enemySize;
        level++;
        lives++;

        ballCount = level + 2;
        enemyCount = level;
        ballsInScreen = ballCount;

        ballPos = new raylib::Vector2[ballCount];
        enemyPos = new raylib::Vector2[enemyCount];
        enemySize = new raylib::Vector2[enemyCount];

        // generate random ball and enemy pos
        for (int b = 0; b < ballCount; ++b) {
            ballPos[b] = Pos::generateRandomPos(Data::ball);
        }
        for (int e = 0; e < enemyCount; ++e) {
            enemyPos[e] = Pos::generateRandomPos(Data::enemy);
            enemySize[e] = EnemyAi::generateEnemySize();
        }
    }
}