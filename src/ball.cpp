#include "ball.h"
#include "data.h"
#include "gameHandler.h"
#include "raylib-cpp.hpp"
#include "pos.h"
#include "utils.h"


void Ball::kill(int ballNum, bool giveScore) {
    ballsInScreen--;
    ballPos[ballNum] = Vector2(-1000, -1000);
    if (giveScore) score++;
    GameHandler::checkLevelUp();

}

void Ball::push(int ballNum, Vector2 pushSteps) {


    ballPos[ballNum] += pushSteps;
    if (!Pos::isPosInScreen(ballPos[ballNum])) {

        Ball::kill(ballNum, false);
    }
    if (Utils::haveCollision(Data::player, Data::ball, ballNum)) {
        Ball::kill(ballNum);
    }
}
