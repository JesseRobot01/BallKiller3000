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