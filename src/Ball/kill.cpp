#include "../balls.h"
#include "../data.h"
#include "../player.h"
#include "../score.h"


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