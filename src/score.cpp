#include "score.h"
#include "data.h"
#include <fstream>

void Score::saveHigh(int score) {
    Score score1;
    std::ofstream highScoreFile("./highScore.txt"); // a temp file
    if (score > highScore) { highScoreFile << score; }
    else { highScoreFile << highScore; }
    highScoreFile.close();
    score1.loadHigh();
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