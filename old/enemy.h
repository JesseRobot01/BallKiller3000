#ifndef BALL_KILLER_ENEMY_H
#define BALL_KILLER_ENEMY_H


class Enemy {
public:
    static void checkPlayerKill();

    static void move();

    static void givePreference(int enemyNumber);
};


#endif
