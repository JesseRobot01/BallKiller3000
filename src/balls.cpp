#include "ball.h"
#include "utils.h"
#include "gameHandler.h"

void Ball::initialise() {

    // check if the ball is not in a specific radius of the player. if yes, regenerate the positions
    pos = generateRandomPos();

    size = Utils::random(minimalSize, maximalSize);
}

raylib::Vector2 Ball::generateRandomPos() {
    int tries = 0;
    bool succeed = false;
    Vector2 generatedPos;

    // after a specific number of tries, just get out of here
    while (!succeed && tries < 100) {
        generatedPos = Utils::generateRandomPos();
        if (isInScreen(generatedPos)) {
            for (int p = 0; p < playerCount; ++p) {
                if (!player[p].pos.CheckCollision(generatedPos, 100)) {
                    succeed = true;
                }
            }
        }

        tries++;
    }
    return generatedPos;
}

void Ball::move(Vector2 moveTo) {
    while (!isInScreen(pos + moveTo)) {
        if (size < 10 && !isDead) {
            ballsInScreen--;
            if (ballsInScreen == 0) GameHandler::levelUp();
            isDead = true;
        }
        size--;
    }
    pos += moveTo;
    for (int p = 0; p < playerCount; ++p) {
        if (hasCollision(player[p])) {
            ballsInScreen--;
            if (ballsInScreen == 0) GameHandler::levelUp();
            isDead = true;
            player[p].score++;
        }
    }
}