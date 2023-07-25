#include "../balls.h"
#include "../data.h"
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
