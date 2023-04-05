#include "player.h"
#include "raylib.h"
#include "data.h"

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

    // checks if the player is touching a ball
    for (int i = 0; i < ballCount; ++i) {
        if (playerPosX <= ballPosX[i] + 30 && playerPosX >= ballPosX[i] - 30 &&
            playerPosY <= ballPosY[i] + 30 && playerPosY >= ballPosY[i] - 30) {
            ballPosX[i] = -100;
            ballPosY[i] = -100;
            ballsOnScreen--;
        }


    }
}