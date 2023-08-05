#include "../pos.h"

bool Pos::isPosInScreen(Vector2 pos) {
    if (Pos::isPosInScreen(pos.x, Data::x) && Pos::isPosInScreen(pos.y, Data::y))
        return true;

    return false;
}

bool Pos::isPosInScreen(float pos, Data::Axis axis) {
    switch (axis) {
        case Data::x:
            if (pos >= 0 && pos <= screenWidth) return true;
            return false;
            break;

        case Data::y:
            if (pos >= 0 && pos <= screenHeight) return true;
            return false;
            break;
    }
    return false;
}

/**
 * A safe pos is an pos where nothing should clip (partially) outside the screen.
 * This function checks for that.
 * Useful to reduce the balls got pushed outside the screen or enemies spawning partially outside the screen.
 * @param pos The pos to check if it is in a safe screen space
 *
 */
bool Pos::isPosSafePos(Vector2 pos) {
    if (pos.x >= 60 && pos.x <= screenWidth - 60) {
        if (pos.y >= 60 && pos.y <= screenHeight - 60) {
            return true;
        }
    }

    return false;
}

/**
* A function to check if something is clipping outside the screen.
 *
 * @param targetType the type to check for it.
 * @param position the position to check for.
 * @param targetNumber the number for the target, ignored if it's the player.
*/
bool Pos::isClippingOutsideScreen(Data::Types targetType, Vector2 position, int targetNumber) {
    switch (targetType) {
        case Data::player:
            if (position.x >= 20 && position.x <= screenWidth - 20) {
                if (position.y >= 20 && position.y <= screenHeight - 20) {
                    return false;
                }
            }

            break;
        case Data::ball:
            if (position.x >= ballSize[targetNumber] && position.x <= screenWidth - ballSize[targetNumber]) {
                if (position.y >= ballSize[targetNumber] && position.y <= screenHeight - ballSize[targetNumber]) {
                    return false;
                }
            }
            break;
        case Data::enemy:
            if (position.x - enemySize[targetNumber].x >= 30 &&
                position.x + enemySize[targetNumber].x <= screenWidth - 30) {
                if (position.y - enemySize[targetNumber].y >= 30 &&
                    position.y + enemySize[targetNumber].y <= screenHeight - 30) {
                    return false;
                }
            }
            break;
    }

    return true;
}