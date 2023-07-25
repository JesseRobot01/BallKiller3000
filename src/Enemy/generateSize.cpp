#include "../enemyAi.h"
#include "../utils.h"


Vector2 EnemyAi::generateEnemySize() {
    if (Utils::random(0, 1) == 1) {
        return Vector2(Utils::random(20, 40), Utils::random(50, 70));
    } else {
        return Vector2(Utils::random(50, 70), Utils::random(20, 40));

    }
}