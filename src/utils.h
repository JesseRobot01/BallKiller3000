#ifndef BALLKILLER3000_UTILS_H
#define BALLKILLER3000_UTILS_H

#include "data.h"

class Utils {
public:
    static int random(int min, int max);

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
    static void checkAllCollisions(Data::Types targetType, Data::Types hasCollisionWith);


/**
 * This checks for collision with the given types and returns a boolean.
 *
 * @param targetType Do i have collision?
 * @param hasCollisionWith With who do i have collision
 * @param targetTypeNumber My number (ignored if i'm the player)
 * @param hasCollisionWithNumber the number from the thing i may touch
 */
    static bool haveCollision(Data::Types targetType, Data::Types hasCollisionWith, int targetTypeNumber,
                              int hasCollisionWithNumber);

    /**
 * This checks for collision with the given types and returns a boolean.
 *
 * @param targetType Do i have collision?
 * @param hasCollisionWith With who do i have collision
 * @param hasCollisionWithNumber the number from the thing i may touch
 */
    static bool haveCollision(Data::Types targetType, Data::Types hasCollisionWith, int hasCollisionWithNumber) {
       return Utils::haveCollision(targetType, hasCollisionWith, 0, hasCollisionWithNumber);
    }
};


#endif