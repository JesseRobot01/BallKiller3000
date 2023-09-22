#include "../enemy.h"
#include "../utils.h"

void Enemy::initialise() {
    // set a random size
    // 50% change for starting flipped
    if (Utils::random(0, 1) == 1) {
        size = Vector2(Utils::random(minimalSizeY, maximalSizeY), Utils::random(minimalSizeX, maximaSizeX));
    } else {
        size = Vector2(Utils::random(minimalSizeX, maximaSizeX), Utils::random(minimalSizeY, maximalSizeY));
    }

    // set ai
    enemyAI = static_cast<aiTypes>(Utils::random(0, 3));

    if (enemyAI == playerPreference) {
        speed = 15;
    }

    pos = generateRandomPos();
}

raylib::Vector2 Enemy::generateRandomPos() {
    int tries = 0;
    bool succeed = false;
    Vector2 generatedPos;

    // after a specific number of tries, just get out of here
    while (!succeed && tries < 100) {
        generatedPos = Utils::generateRandomPos();
        if (isInScreen(generatedPos)) {
            for (int p = 0; p < playerCount; ++p) {
                if (!player[p].pos.CheckCollision(generatedPos, 150)) {
                    succeed = true;
                }
            }
        }

        tries++;
    }
    return generatedPos;
}