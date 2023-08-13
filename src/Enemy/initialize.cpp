#include "../enemyAi.h"
#include "../utils.h"


Vector2 EnemyAi::generateEnemySize() {
    if (Utils::random(0, 1) == 1) {
        return Vector2(Utils::randomFloat(minimalEnemySizeY, maximalEnemySizeY),
                       Utils::randomFloat(minimalEnemySizeX, maximalEnemySizeX));

    } else {
        return Vector2(Utils::random(minimalEnemySizeX, maximalEnemySizeX),
                       Utils::randomFloat(minimalEnemySizeY, maximalEnemySizeY));

    }
}

void EnemyAi::initializeEnemyAi(int enemyNum) {
    enemySize[enemyNum] = EnemyAi::generateEnemySize();

    // 1 = neutral, 2 = he likes balls, 3 = he likes players (oh no), 4 = he likes others
    enemyPreference[enemyNum] = Utils::random(1, 4);
}