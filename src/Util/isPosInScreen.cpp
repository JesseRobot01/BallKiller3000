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