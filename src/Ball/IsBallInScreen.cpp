#include "../balls.h"
#include "../data.h"


bool Balls::isBallInScreen(int ballNum) {

    if (ballPosX[ballNum] >= 0 && ballPosX[ballNum] <= screenWidth && ballPosY[ballNum] >= 0 &&
        ballPosY[ballNum] <= screenHeight)
        return true;

    return false;
}