#include "../pos.h"
#include "../utils.h"
#include "raylib-cpp.hpp"

Vector2 Pos::generateRandomPos(Data::Types type) {

    Vector2 pos = Pos::generateRandomPos();
    int tries = 0;

    // check if the ball is not in a specific radius of the player. if yes, regenerate the positions
    if (type == Data::ball) {
        // after a specific number of tries, just get out of here
        while (playerPos.CheckCollision(pos, 100 + playerSize) && tries < 100) {
            pos = Pos::generateRandomPos();
            tries++;
        }
    }

    // same for the enemy
    if (type == Data::enemy) {
        while (playerPos.CheckCollision(pos, 130 + playerSize) && tries < 100) {
            pos = Pos::generateRandomPos();
            tries++;
        }
    }

    return pos;
}

Vector2 Pos::generateRandomPos() {
    return Vector2(Utils::randomFloat(60, screenWidth - 60),
                   Utils::randomFloat(60, screenHeight - 60));
}