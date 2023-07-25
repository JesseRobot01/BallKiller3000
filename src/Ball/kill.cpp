#include "../ball.h"
#include "../data.h"
#include "../gameHandler.h"

void Ball::kill(int ballNum, bool giveScore) {
    ballsInScreen--;
    ballPos[ballNum] = Vector2(-1000, -1000);
    if (giveScore) score++;
    GameHandler::checkLevelUp();

}