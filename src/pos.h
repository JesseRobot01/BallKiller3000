#ifndef BALLKILLER3000_POS_H
#define BALLKILLER3000_POS_H

#include "raylib-cpp.hpp"
#include "data.h"

class Pos {
public:
    static Vector2 generateRandomPos(Data::Types);

    static void getPlayerMoveInput();

    static void movePlayer(Vector2 moveDistance, int playerNum);

    static bool isPosInScreen(Vector2 pos);

    static bool isPosInScreen(float pos, Data::Axis axis);

    /**
 * A safe pos is an pos where nothing should clip (partially) outside the screen.
 * This function checks for that.
 * Useful to reduce the balls got pushed outside the screen or enemies spawning partially outside the screen.
 * @param pos The pos to check if it is in a safe screen space
 *
 */
    static bool isPosSafePos(Vector2 pos);


    /**
* A function to check if something is clipping outside the screen.
 *
 * @param targetType the type to check for it
 * @param position the position to check for.
 * @param targetNumber the number for the target, ignored if it's the player.
 *
*/
    static bool isClippingOutsideScreen(Data::Types targetType, Vector2 position, int targetNumber);

    /**
* A function to check if something is clipping outside the screen.
 *
 * @param targetType the type to check for it
 * @param targetNumber the number for the target.
 *
*/
    static bool isClippingOutsideScreen(Data::Types targetType, int targetNumber) {
        switch (targetType) {

            case Data::player:
                return Pos::isClippingOutsideScreen(targetType, playerPos[targetNumber], -1);
            case Data::ball:
                Pos::isClippingOutsideScreen(targetType, ballPos[targetNumber], targetNumber);
            case Data::enemy:
                Pos::isClippingOutsideScreen(targetType, enemyPos[targetNumber], targetNumber);
        }

    };

    /**
* A function to check if something is clipping outside the screen.
*
* @param targetType the type to check for it
 * @param position the position to check for.
*
*/
    static bool isClippingOutsideScreen(Data::Types targetType, Vector2 position) {
        return Pos::isClippingOutsideScreen(targetType, position, -1);

    };

    /**
* A function to check if something is clipping outside the screen.
 *
 * @param targetType the type to check for it
 *
*/
    static bool isClippingOutsideScreen(Data::Types targetType) {
        return Pos::isClippingOutsideScreen(targetType, -1);

    };

private:
    static Vector2 generateRandomPos();


};

#endif
