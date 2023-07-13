#include "score.h"
#include "data.h"
#include <fstream>

void Score::saveHigh(int score) {
    std::ofstream highScoreFile("./highScore.txt"); // a temp file
    if (score > highScore) { highScoreFile << score; }
    else { highScoreFile << highScore; }
    highScoreFile.close();
    Score::loadHigh();
}

void Score::loadHigh() {
    std::ifstream highScoreFile("./highScore.txt");
    if (highScoreFile) {
        highScoreFile >> highScore;
        highScoreFile.close();
    } else {
        highScore = 0;
    }
}

void Score::checkIfExtraLife() {
    if (scoreCount % 10 == 0) {
        liveCount++;
    }
}