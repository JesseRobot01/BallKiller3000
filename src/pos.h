#ifndef BALLKILLER3000_POS_H
#define BALLKILLER3000_POS_H

#include "raylib-cpp.hpp"
#include "data.h"

class Pos {
public:
    static Vector2 generateRandomPos(Data::Types);

    static void getPlayerMoveInput();

    static void movePlayer(float moveDistance, Data::Axis axis);

    static bool isPosInScreen(Vector2 pos);

    static bool isPosInScreen(float pos, Data::Axis axis);
};

#endif
