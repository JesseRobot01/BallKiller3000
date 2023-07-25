#include "../pos.h"
#include "../utils.h"
#include "raylib-cpp.hpp"

Vector2 Pos::generateRandomPos(Data::Types type) {

    float posX = Utils::random(1, screenWidth);
    float posY = Utils::random(1, screenHeight);


    // check if the ball is not in a specific radius of the player. if yes, regenerate the positions
    if (type == Data::ball) {
        while (playerPos.CheckCollision(Vector2(posX, posY), 120)) {
            posX = Utils::random(1, screenWidth);
            posY = Utils::random(1, screenHeight);
        }
    }

    // same for the enemy
    if (type == Data::enemy) {
        while (playerPos.CheckCollision(Vector2(posX, posY), 150)) {
            posX = Utils::random(1, screenWidth);
            posY = Utils::random(1, screenHeight);
        }
    }

    return Vector2(posX, posY);


}

