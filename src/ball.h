#ifndef BALLKILLER3000_BALL_H
#define BALLKILLER3000_BALL_H

#include "raylib-cpp.hpp"


class Ball {
public:

    static void kill(int ballNum, bool giveScore = true);

    static void push(int ballNum, Vector2 pushSteps);
};

#endif
