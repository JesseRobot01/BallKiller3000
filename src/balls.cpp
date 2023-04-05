#include "balls.h"
#include "data.h"
#include <cstdlib>
#include <iostream>

int Balls::generateBallPos(char axis) {
    int maxNum;
    int output;
    if (tolower(axis) == 'x') maxNum = screenWidth;
    else if (tolower(axis) == 'y') maxNum = screenHeight;
    else maxNum = -100;

    output = rand() % (maxNum - 0 + 1) + 0;
    // This program will create some sequence of random
    // numbers on every program run within range lb to ub

    std::cout << output << " for axis " << axis << "\n";
    return output;
}