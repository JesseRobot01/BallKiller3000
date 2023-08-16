#include <iostream>
#include "../utils.h"
#include "../data.h"
#include "../ball.h"
#include "../enemyAi.h"


/**
 * This checks for collision for every x with every x and execute the corresponding action
 *
 * @param targetType Do i have collision?
 * @param hasCollisionWith With who do i have collision?
 *
 * I don't know how i can explain it in at a better way lmao
 * @example <code>checkAllCollisions(Data::Player, Data::Ball);</code><br>
 * Check if the player has collision with all the balls, if yes, execute a corresponding code for that ball.
 *<br><br>
 * @example <code>checkAllCollisions(Data::Enemy, Data::Ball);</code><br>
 * Check if all the enemies have collision with all the balls, if yes, execute an corresponding action
 *<br><br>
 * @example <code>checkAllCollisions(Data::Ball, Data::Ball);</code><br>
 * Check if all the balls have collision with all the other balls, if yes, execute an corresponding action
 */
void Utils::checkAllCollisions(Data::Types targetType, Data::Types hasCollisionWith) {
    if (targetType == Data::player) {
        if (hasCollisionWith == Data::ball) {
            for (int B = 0; B < ballCount; ++B) {
                if (Utils::haveCollision(targetType, hasCollisionWith, B)) { Ball::kill(B); }
                if (isGameMultiPlayerGame) {
                    if (Utils::hasCollision(targetType, hasCollisionWith, 1, B)) { Ball::kill(B, 1); }
                }
            }


        }
        if (hasCollisionWith == Data::enemy) {
            for (int e = 0; e < enemyCount; ++e) {
                if (Utils::haveCollision(targetType, hasCollisionWith, e)) {
                    EnemyAi::killPlayer(e, 0);
                }
                if (isGameMultiPlayerGame) {
                    if (Utils::hasCollision(targetType, hasCollisionWith, 1, e)) { EnemyAi::killPlayer(e, 1); }
                }
            }
        }
    }

    if (targetType == Data::ball) {
        if (hasCollisionWith == Data::player) {
            Utils::checkAllCollisions(hasCollisionWith, targetType);
        }

        if (hasCollisionWith == Data::enemy) {
            for (int e = 0; e < enemyCount; ++e) {
                for (int b = 0; e < ballCount; ++e) {

                    if (Utils::hasCollision(targetType, hasCollisionWith, b, e)) {
                        std::cout << "Ball number " + std::to_string(b) + " has collision with enemy number " +
                                     std::to_string(e) + "\n";

                    }
                }
            }

        }


    }

    if (targetType == Data::enemy) {
        if (hasCollisionWith == Data::player) {
            Utils::checkAllCollisions(hasCollisionWith, targetType);
        }

        if (hasCollisionWith == Data::ball) {
            Utils::checkAllCollisions(hasCollisionWith, targetType);
        }


    }

}

/**
 * This checks for collision with the given types and returns a boolean.
 *
 * @param targetType Do i have collision?
 * @param hasCollisionWith With who do i have collision
 * @param targetTypeNumber My number
 * @param hasCollisionWithNumber the number from the thing i may touch
 */
bool
Utils::hasCollision(Data::Types targetType, Data::Types hasCollisionWith, int targetTypeNumber,
                    int hasCollisionWithNumber) {
    if (targetType == Data::player) {
        if (hasCollisionWith == Data::ball) {
            if (playerPos[targetTypeNumber].CheckCollision(ballPos[hasCollisionWithNumber],
                                                           playerSize[targetTypeNumber] - 5 +
                                                           ballSize[hasCollisionWithNumber]))
                return true;
        }
        if (hasCollisionWith == Data::enemy) {
            if (playerPos[targetTypeNumber].CheckCollision(
                    Rectangle(enemyPos[hasCollisionWithNumber].x - playerSize[targetTypeNumber] - 5,
                              enemyPos[hasCollisionWithNumber].y - playerSize[targetTypeNumber] - 5,
                              enemySize[hasCollisionWithNumber].x + playerSize[targetTypeNumber] + 10,
                              enemySize[hasCollisionWithNumber].y + playerSize[targetTypeNumber] + 10)))

                return true;
        }
    }

    if (targetType == Data::enemy) {
        if (hasCollisionWith == Data::ball) {
            if (ballPos[hasCollisionWithNumber].CheckCollision(
                    Rectangle(enemyPos[targetTypeNumber].x - ballSize[hasCollisionWithNumber] - 5,
                              enemyPos[targetTypeNumber].y - ballSize[hasCollisionWithNumber] - 5,
                              enemySize[targetTypeNumber].x + ballSize[hasCollisionWithNumber] + 10,
                              enemySize[targetTypeNumber].y + ballSize[hasCollisionWithNumber] + 10))) { return true; }

        }
        if (hasCollisionWith == Data::player)
            return Utils::haveCollision(hasCollisionWith, targetType, targetTypeNumber);
    }

    if (targetType == Data::ball) {
        if (hasCollisionWith == Data::enemy) {

            return Utils::hasCollision(hasCollisionWith, targetType, hasCollisionWithNumber, targetTypeNumber);
        }
        if (hasCollisionWith == Data::player)
            return Utils::haveCollision(hasCollisionWith, targetType, targetTypeNumber);
    }
    return false;
}