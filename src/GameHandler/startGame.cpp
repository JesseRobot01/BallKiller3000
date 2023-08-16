#include "../gameHandler.h"
#include "../data.h"


void GameHandler::startGame() {
    // first time run things
    score[0] = 0;
    score[1] = 0;
    lives[0] = 2; // there will be another while loading the rest
    lives[1] = -1;
    level = 0;
    highScore = GameHandler::loadHigh();
    playerPos[0] = Vector2(screenWidth / 2, screenHeight / 2);
    playerPos[1] = Vector2(-1000, -1000);

    if (isGameMultiPlayerGame) {
        playerPos[0] = Vector2(screenWidth / 2 - 60, screenHeight / 2);
        playerPos[1] = Vector2(screenWidth / 2 + 60, screenHeight / 2);

        lives[1] = 2;
    }

    isGameOver = false;

// the rest of the code also happens when level up
    GameHandler::checkLevelUp(true);

}