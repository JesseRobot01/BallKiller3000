#include "../gameHandler.h"
#include "../data.h"
#include "../pos.h"
#include "../enemyAi.h"
#include "../utils.h"

void GameHandler::checkLevelUp(bool firstTimeRun) {
    if (ballsInScreen <= 0 || firstTimeRun) {
        delete[] ballPos;
        delete[] enemies;
        delete[] ballSize;
        level++;
        if (level % 2) {
            lives[0]++;
            if (isGameMultiPlayerGame) lives[1]++;
        }

        ballCount = level + 2;
        enemyCount = level;
        ballsInScreen = ballCount;
        enemiesInScreen = enemyCount;

        ballPos = new raylib::Vector2[ballCount];
        enemies = new Enemy[enemyCount];
        ballSize = new float[ballCount];

        // generate random ball and enemy pos
        for (int b = 0; b < ballCount; ++b) {
            ballPos[b] = Pos::generateRandomPos(Data::ball);
            ballSize[b] = Utils::random(minimalBallSize, maximalBallSize);
        }
        for (int e = 0; e < enemyCount; ++e) {
            enemies[e].enemyNumber = e;
            enemies[e].pos = Pos::generateRandomPos(Data::enemy);
            enemies[e].initializeAi();
        }
    }
}