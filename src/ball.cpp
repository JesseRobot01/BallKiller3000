#include "ball.h"
#include "data.h"
#include "gameHandler.h"
#include "raylib-cpp.hpp"
#include "pos.h"
#include "utils.h"


void Ball::kill(int ballNum, int playerNum, bool giveScore) {
    ballsInScreen--;
    ballPos[ballNum] = Vector2(-1000, -1000);
    if (giveScore) score[playerNum]++;
    GameHandler::checkLevelUp();

}

void Ball::push(int ballNum, Vector2 pushSteps) {

    while (Pos::isClippingOutsideScreen(Data::ball, ballPos[ballNum] + pushSteps, ballNum)) {
        if (!Pos::isPosInScreen(ballPos[ballNum])) {
            break;
        }
        if (ballSize[ballNum] <= 10) {
            Ball::kill(ballNum, false);
        }
        ballSize[ballNum]--;
    }

    ballPos[ballNum] += pushSteps;


    if (Utils::haveCollision(Data::player, Data::ball, ballNum)) {
        Ball::kill(ballNum);
    }
}
