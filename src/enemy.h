#ifndef BALLKILLER3000_ENEMY_H
#define BALLKILLER3000_ENEMY_H

#include "raylib-cpp.hpp"

class Enemy {
public:
    int enemyNumber; // for self-awareness.

    raylib::Vector2 pos;
    int preference;
    raylib::Vector2 size;

    float minimalSizeX = 50;
    float minimalSizeY = 20;
    float maximaSizeX = 70;
    float maximalSizeY = 40;

    void killPlayer(int playerNum);

    void move(raylib::Vector2 distance);

    void moveTo(raylib::Vector2 targetPos, float maxSteps);

    void initializeAi();


private:
    Vector2 generateEnemySize();

};

#endif
