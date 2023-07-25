#ifndef BALLKILLER3000_ENEMYAI_H
#define BALLKILLER3000_ENEMYAI_H

#include "raylib-cpp.hpp"

class EnemyAi {
public:
    static Vector2 generateEnemySize();

    static void killPlayer(int enemyNum);
};

#endif