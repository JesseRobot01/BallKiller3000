#include "../gameHandler.h"
#include "../data.h"
#include "../pos.h"

void GameHandler::startGame() {
    // first time run things
    score = 0;
    lives = 0; // there will be another while loading the rest
    level = 0;
    highScore = GameHandler::loadHigh();
    playerPos = Vector2(screenWidth / 2, screenHeight / 2);
    isGameOver = false;

// the rest of the code also happens when level up
    GameHandler::checkLevelUp(true);

}