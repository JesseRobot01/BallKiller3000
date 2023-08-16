#ifndef BALLKILLER3000_ENEMYAI_H
#define BALLKILLER3000_ENEMYAI_H

#include "raylib-cpp.hpp"
#include "data.h"

class EnemyAi {
public:

    static void killPlayer(int enemyNum, int playerNum);

    static void initializeEnemyAi(int enemyNum);

    static void move(int enemyNum, raylib::Vector2 distance);

    static void moveTo(int enemyNum, raylib::Vector2 targetPos, float maxSteps);

    static void generateMove();

private:
    static Vector2 generateEnemySize();


};

#endif