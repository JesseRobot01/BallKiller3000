#include <fstream>
#include "../gameHandler.h"
#include "../data.h"

int GameHandler::loadHigh() {
    int tmpScore = 0;

    std::ifstream highScoreFile("./highScore.txt");
    if (highScoreFile) {
        highScoreFile >> tmpScore;
        highScoreFile.close();
    } else {
        tmpScore = 0;
    }

    return tmpScore;
}

void GameHandler::saveHigh(bool forced) {
    std::ofstream highScoreFile("./highScore.txt"); // a temp file
    if ((score[0] > highScore && !isGameMultiPlayerGame) || forced) { highScoreFile << score; }
    else { highScoreFile << highScore; }

    highScoreFile.close();

}