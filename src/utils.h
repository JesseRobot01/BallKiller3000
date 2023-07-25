#ifndef BALLKILLER3000_UTILS_H
#define BALLKILLER3000_UTILS_H

#include "data.h"

class Utils {
public:
    static int random(int min, int max);

    static void checkAllCollision(Data::Types target, Data::Types checkCollisionWith);

    static void
    checkBallTouchPlayer(Data::Types target, Data::Types checkCollisionWith, int targetNum = 0, int CollisionNum = 0);
};

#endif