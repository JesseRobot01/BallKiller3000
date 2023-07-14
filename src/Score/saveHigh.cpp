#include "../score.h"
#include "../data.h"
#include <fstream>

void Score::saveHigh(int score) {
    std::ofstream highScoreFile("./highScore.txt"); // a temp file
    if (score > highScore) { highScoreFile << score; }
    else { highScoreFile << highScore; }
    highScoreFile.close();
    Score::loadHigh();
}