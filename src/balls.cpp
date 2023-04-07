#include "balls.h"
#include "data.h"
#include "player.h"
#include <cstdlib>
#include <iostream>

int Balls::generateBallPos(char axis) {
    int maxNum;
    int output;
    if (tolower(axis) == 'x') maxNum = screenWidth;
    else if (tolower(axis) == 'y') maxNum = screenHeight;
    else maxNum = -100;

    output = rand() % (maxNum - 0 + 1) + 0;

    if (output <= 100) output = 100;
    if (tolower(axis) == 'x' && output >= screenWidth - 100) output = screenWidth - 100;
    if (tolower(axis) == 'y' && output >= screenHeight - 100) output = screenHeight - 100;


    if (!tolower(axis) == 'x') {
        if (!tolower(axis) == 'y') {
            std::cout << "The axis was " << axis << ", now it is putted outside the screen\n";
            output = -100;
        }
    }

    return output;
}

void Balls::kill() {
    Player player;

    // checks if the player is touching a ball
    for (int i = 0; i < ballCount; ++i) {
        if (playerPosX <= ballPosX[i] + 30 && playerPosX >= ballPosX[i] - 30 &&
            playerPosY <= ballPosY[i] + 30 && playerPosY >= ballPosY[i] - 30) {
            ballPosX[i] = -100;
            ballPosY[i] = -100;
            ballsOnScreen--;
        }
    };
    if (ballsOnScreen == 0) player.finishesLevel();
}