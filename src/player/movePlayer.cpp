#include <iostream>
#include "../data.h"
#include "../pos.h"
#include "../ball.h"
#include "../utils.h"

void Pos::getPlayerMoveInput() {
    raylib::Vector2 moveTo;

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        moveTo.y = -moveSpeed;
    }

    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        moveTo.y = moveSpeed;
    }

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        moveTo.x = -moveSpeed;
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        moveTo.x = moveSpeed;
    }


    // calculates the axis he wants with control stick
    if (isTouchingScreen) {
        moveTo = controlStickStartPos.MoveTowards(controlStickCurrentPos, moveSpeed) - controlStickStartPos;
    }

    Pos::movePlayer(moveTo);

}

void Pos::movePlayer(Vector2 moveDistance) {
    if (Pos::isPosInScreen(playerPos + moveDistance)) {
        playerPos += moveDistance;
        Utils::checkAllCollisions(Data::player, Data::ball);
    }
}