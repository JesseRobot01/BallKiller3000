#ifndef BALLKILLER3000_UTILS_H
#define BALLKILLER3000_UTILS_H

#include "data.h"

class Utils {
public:
    static int random(int min, int max);

    static float random(float min, float max);

    // this 2 is to make sure if I really want an int, I get an int, or float
    static float randomFloat(float min, float max) {
        return random(min, max);
    }

    static int randomInt(int min, int max) {
        return random(min, max);
    }

    // random pos generator
    static raylib::Vector2 generateRandomPos() {
        return Vector2(random(0.0, screenWidth), random(0.0, screenHeight));
    }

    static int getNearestBall(raylib::Vector2 pos, bool ignoreAlmostDead = false, int ignoreNumber = -1);

    static int getNearestEnemy(raylib::Vector2 pos, int ignoreNumber = -1);

    static int getNearestPlayer(raylib::Vector2 pos, int ignoreNumber = -1);
};


#endif