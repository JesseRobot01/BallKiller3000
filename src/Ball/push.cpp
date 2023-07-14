#include "../balls.h"
#include "../data.h"


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