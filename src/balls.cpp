#include "balls.h"
#include "data.h"
#include "player.h"
#include "data.h"
#include "score.h"
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
    switch (axis) {
        case 'x':
            if (output <= playerPosX + 50 && output >= playerPosX - 50) {
                output + 300;
            }
            break;
        case 'y':
            if (output <= playerPosY + 50 && output >= playerPosY - 50) {
                output + 300;
            }
            break;
    }
    return output;
}

void Balls::kill() {
    // checks if the player is touching a ball
    for (int i = 0; i < ballCount; ++i) {
        if (playerPosX <= ballPosX[i] + 30 && playerPosX >= ballPosX[i] - 30 &&
            playerPosY <= ballPosY[i] + 30 && playerPosY >= ballPosY[i] - 30) {
            ballPosX[i] = -10000;
            ballPosY[i] = -10000;
            ballsOnScreen--;
            scoreCount++;
            Score::checkIfExtraLife();
        }
    }
    if (ballsOnScreen == 0) Player::finishesLevel();
}

void Balls::push(int ballNum, int pushSteps, char axis) {
    bool isSuccessfully = false;
    switch (axis) {
        case 'x': {

            ballPosX[ballNum] += pushSteps;
            isSuccessfully = Balls::isBallInScreen(ballNum);
        }

        case 'y': {
            {
                ballPosY[ballNum] += pushSteps;
                isSuccessfully = Balls::isBallInScreen(ballNum);
            }


        }
            // well, let's trow the ball away
            if (!isSuccessfully) {
                ballPosX[ballNum] = generateBallPos('x');
                ballPosY[ballNum] = generateBallPos('y');
            }
    }

}


bool Balls::isBallInScreen(int ballNum) {

    if (ballPosX[ballNum] >= 0 && ballPosX[ballNum] <= screenWidth && ballPosY[ballNum] >= 0 &&
        ballPosY[ballNum] <= screenHeight)
        return true;

    return false;
}