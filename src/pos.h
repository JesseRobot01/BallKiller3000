#ifndef BALLKILLER3000_POS_H
#define BALLKILLER3000_POS_H

#include "raylib-cpp.hpp"
#include "data.h"

class Pos {
public:
    static Vector2 generateRandomPos(Data::Types);

    static void getPlayerMoveInput();

    static void movePlayer(Vector2 moveDistance);

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

private:
    static Vector2 generateRandomPos();
};

#endif
