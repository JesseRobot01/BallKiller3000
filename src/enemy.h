#ifndef BALLKILLER3000_ENEMY_H
#define BALLKILLER3000_ENEMY_H

#include "raylib-cpp.hpp"

class Enemy {
public:
    raylib::Vector2 pos;
    int preference;
    float minimalSizeX = 50;
    float minimalSizeY = 20;
    float maximaSizeX = 70;
    float maximalSizeY = 40;
};

#endif
