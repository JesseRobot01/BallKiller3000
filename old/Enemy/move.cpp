#include <iostream>
#include "../enemy.h"
#include "../data.h"
#include "../balls.h"

void Enemy::move() {
    for (int i = 0; i < enemyCount; ++i) {
        int moveDirection;
        int moveCounter;
        int sizeBetweenTarget;
        int sizeBetweenCalculatedBallX;
        int sizeBetweenCalculatedBallY;
        int sizeBetweenClosesBallX;
        int sizeBetweenClosesBallY;
        int closestBallNum;

        if (enemyPreference[i] == 1) moveDirection = rand() % (4 - 0 + 1) + 0;
        else moveDirection = rand() % (8 - 0 + 1) + 0;

        moveCounter = rand() % (30 - 0 + 1) + 0;
        if (enemyPreference[i] == 3)
            moveCounter = rand() % (
                    20 - 0 + 1) + 0;
        if (enemyPosX[i] > -30 && enemyPosX[i] < screenWidth + 30 &&
            enemyPosY[i] > 0 - 30 && enemyPosY[i] < screenHeight + 30) {
            // handles the random trows

            switch (moveDirection) {
                case 1:
                    if (enemyPosX[i] + moveCounter <= screenWidth) { enemyPosX[i] += moveCounter; }

                    break;

                case 2:
                    if (enemyPosX[i] - moveCounter >= 0) { enemyPosX[i] -= moveCounter; }

                    break;

                case 3:
                    if (enemyPosY[i] + moveCounter <= screenHeight) { enemyPosY[i] += moveCounter; }

                    break;

                case 4:
                    if (enemyPosY[i] - moveCounter >= 0) { enemyPosY[i] -= moveCounter; }

                    break;

                case 5:
                case 6:

                    if (enemyPreference[i] == 2) {
                        sizeBetweenClosesBallX = 999;
                        sizeBetweenClosesBallY = 999;

                        for (int b = 0; b < ballCount; ++b) {
                            // get the closest ball on x-axis and y-axis
                            sizeBetweenCalculatedBallX = enemyPosX[i] - ballPosX[b];
                            sizeBetweenCalculatedBallY = enemyPosY[i] - ballPosY[b];
                            if (sizeBetweenCalculatedBallX < 0) sizeBetweenCalculatedBallX * -1;
                            if (sizeBetweenCalculatedBallY < 0) sizeBetweenCalculatedBallY * -1;

                            if (sizeBetweenCalculatedBallX + sizeBetweenCalculatedBallY <=
                                sizeBetweenClosesBallX + sizeBetweenClosesBallY) {

                                sizeBetweenClosesBallX = sizeBetweenCalculatedBallX;
                                sizeBetweenClosesBallY = sizeBetweenCalculatedBallY;
                                closestBallNum = b;
                            }

                        }


                        sizeBetweenTarget = enemyPosX[i] - ballPosX[closestBallNum];

                        if (sizeBetweenTarget < 0)
                            enemyPosX[i] += moveCounter;
                        else if (sizeBetweenTarget > 0)
                            enemyPosX[i] -= moveCounter;


                    } else if (enemyPreference[i] == 3) {
                        sizeBetweenTarget = enemyPosX[i] - playerPosX;

                        if (sizeBetweenTarget < 0)
                            enemyPosX[i] += moveCounter;
                        else if (sizeBetweenTarget > 0)
                            enemyPosX[i] -= moveCounter;

                    }
                    break;

                case 7:
                case 8:
                    if (enemyPreference[i] == 2) {
                        sizeBetweenClosesBallX = 999;
                        sizeBetweenClosesBallY = 999;

                        for (int b = 0; b < ballCount; ++b) {
                            // get the closest ball on x-axis and y-axis
                            sizeBetweenCalculatedBallX = enemyPosX[i] - ballPosX[b];
                            sizeBetweenCalculatedBallY = enemyPosY[i] - ballPosY[b];
                            if (sizeBetweenCalculatedBallX < 0) sizeBetweenCalculatedBallX * -1;
                            if (sizeBetweenCalculatedBallY < 0) sizeBetweenCalculatedBallY * -1;

                            if (sizeBetweenCalculatedBallX + sizeBetweenCalculatedBallY <=
                                sizeBetweenClosesBallX + sizeBetweenClosesBallY) {

                                sizeBetweenClosesBallX = sizeBetweenCalculatedBallX;
                                sizeBetweenClosesBallY = sizeBetweenCalculatedBallY;
                                closestBallNum = b;
                            }

                        }


                        sizeBetweenTarget = enemyPosY[i] - ballPosY[closestBallNum];

                        if (sizeBetweenTarget < 0)
                            enemyPosY[i] += moveCounter;
                        else if (sizeBetweenTarget > 0)
                            enemyPosY[i] -= moveCounter;

                    } else if (enemyPreference[i] == 3) {
                        sizeBetweenTarget = enemyPosY[i] - playerPosY;

                        if (sizeBetweenTarget < 0)
                            enemyPosY[i] += moveCounter;
                        else if (sizeBetweenTarget > 0)
                            enemyPosY[i] -= moveCounter;

                    }
                    break;
            }

            // checks if an enemy is in inside a ball, if yes, push the ball
            // this part is stolen (again)
            for (int b = 0; b < ballCount; ++b) {
                if (ballPosX[b] >= enemyPosX[i] && ballPosX[b] <= enemyPosX[i] + 60 &&
                    ballPosY[b] >= enemyPosY[i] && ballPosY[b] <= enemyPosY[i] + 30) {
                    Balls ball;
                    switch (moveDirection) {
                        case 1:
                            Balls::push(b, moveCounter, 'x');
                            break;
                        case 2:
                            Balls::push(b, -moveCounter, 'x');
                            break;
                        case 3:
                            Balls::push(b, moveCounter, 'Y');
                            break;
                        case 4:
                            Balls::push(b, -moveCounter, 'Y');
                            break;

                        case 5:
                        case 6:

                            if (sizeBetweenTarget < 0)
                                Balls::push(b, moveCounter, 'x');
                            else if (sizeBetweenTarget > 0)
                                Balls::push(b, -moveCounter, 'x');
                            break;

                        case 7:
                        case 8:
                            if (sizeBetweenTarget < 0)
                                Balls::push(b, -moveCounter, 'y');
                            else if (sizeBetweenTarget > 0)
                                Balls::push(b, moveCounter, 'y');
                            break;

                    }
                }
            }
        }
    }
}