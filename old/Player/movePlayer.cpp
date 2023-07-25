#include "../player.h"
#include "raylib.h"
#include "../data.h"
#include "../balls.h"
#include "../enemy.h"


void Player::movePlayer() {
    // the basic movement
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        if (playerPosY >= 0)
            playerPosY -= moveSpeed;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        if (playerPosY <= screenHeight)
            playerPosY += moveSpeed;
    }

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        if (playerPosX >= 0)
            playerPosX -= moveSpeed;

    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        if (playerPosX <= screenWidth)
            playerPosX += moveSpeed;
    }
    Balls::kill();
    Enemy::checkPlayerKill();
}