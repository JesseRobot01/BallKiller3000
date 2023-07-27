#include "../gameHandler.h"
#include "../data.h"

void GameHandler::endGame(bool forced) {
    if (lives <= 0 || forced) {
        GameHandler::saveHigh();
        isGameOver = true;
    }
}