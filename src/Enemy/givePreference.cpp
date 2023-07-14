#include <iostream>
#include "../enemy.h"
#include "../data.h"


void Enemy::givePreference(int enemyNumber) {
    int AISetting;
    AISetting = rand() % (5 - 0 + 1) + 0;

    if (AISetting == 4) AISetting = 2;
    if (AISetting == 5) AISetting = 3;

    // 1 = neutral, 2 = ballPreferred, 3 = PlayerPreferred

    enemyPreference[enemyNumber] = AISetting; // HOW DID I FORGET THIS FOR SUCH A LONG TIME!!!!!!

}