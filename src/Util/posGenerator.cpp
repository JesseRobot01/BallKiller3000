#include "../pos.h"
#include "../utils.h"
#include "raylib-cpp.hpp"

Vector2 Pos::generateRandomPos(Data::Types type) {

    Vector2 pos = Pos::generateRandomPos();


    // check if the ball is not in a specific radius of the player. if yes, regenerate the positions
    if (type == Data::ball) {
        while (playerPos.CheckCollision(pos, 120)) {
            pos = Pos::generateRandomPos();
        }
    }

    // same for the enemy
    if (type == Data::enemy) {
        while (playerPos.CheckCollision(pos, 150)) {
            pos = Pos::generateRandomPos();
        }
    }

    return pos;
}

Vector2 Pos::generateRandomPos() {
    return Vector2(Utils::random(60, screenWidth - 60),
                   Utils::random(60, screenHeight - 60));
}