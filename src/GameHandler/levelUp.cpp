#include "../gameHandler.h"
#include "../data.h"
#include "../pos.h"
#include "../enemyAi.h"
#include "../utils.h"

void GameHandler::checkLevelUp(bool firstTimeRun) {
    if (ballsInScreen <= 0 || firstTimeRun) {
        delete[] ballPos;
        delete[] enemyPos;
        delete[] enemySize;
        delete[] enemyPreference;
        delete[] ballSize;
        level++;
        if (level % 2) lives++;

        ballCount = level + 2;
        enemyCount = level;
        ballsInScreen = ballCount;
        enemiesInScreen = enemyCount;

        ballPos = new raylib::Vector2[ballCount];
        enemyPos = new raylib::Vector2[enemyCount];
        enemySize = new raylib::Vector2[enemyCount];
        enemyPreference = new int[enemyCount];
        ballSize = new float[ballCount];

        // generate random ball and enemy pos
        for (int b = 0; b < ballCount; ++b) {
            ballPos[b] = Pos::generateRandomPos(Data::ball);
            ballSize[b] = Utils::random(minimalBallSize, maximalBallSize);
        }
        for (int e = 0; e < enemyCount; ++e) {
            enemyPos[e] = Pos::generateRandomPos(Data::enemy);
            EnemyAi::initializeEnemyAi(e);
        }
    }
}