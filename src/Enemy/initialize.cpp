#include "../enemyAi.h"
#include "../utils.h"


Vector2 EnemyAi::generateEnemySize() {
    if (Utils::random(0, 1) == 1) {
        return Vector2(Utils::randomFloat(enemies[0].minimalSizeY, enemies[0].maximalSizeY), // Zero just works.
                       Utils::randomFloat(enemies[0].minimalSizeX, enemies[0].maximaSizeX));

    } else {
        return Vector2(Utils::random(enemies[0].minimalSizeX, enemies[0].maximaSizeX),
                       Utils::randomFloat(enemies[0].minimalSizeY, enemies[0].maximalSizeY));

    }
}

void EnemyAi::initializeEnemyAi(int enemyNum) {
    enemies[enemyNum].size = EnemyAi::generateEnemySize();

    // 1 = neutral, 2 = he likes balls, 3 = he likes players (oh no), 4 = he likes others
    enemies[enemyNum].preference = Utils::random(1, 4);
}