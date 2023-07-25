#include "../score.h"
#include "../data.h"
#include <fstream>


void Score::loadHigh() {
    std::ifstream highScoreFile("./highScore.txt");
    if (highScoreFile) {
        highScoreFile >> highScore;
        highScoreFile.close();
    } else {
        highScore = 0;
    }
}