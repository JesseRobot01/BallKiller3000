#include "../data.h"
#include "../pos.h"
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
    if (!Pos::isClippingOutsideScreen(Data::player, playerPos + moveDistance)) {
        playerPos += moveDistance;
        Utils::checkAllCollisions(Data::player, Data::ball);
        return;
    }

    // if it can't move altogether, try moving it by axis.
    if (!Pos::isClippingOutsideScreen(Data::player, playerPos + Vector2(moveDistance.x, 0))) {
        playerPos += Vector2(moveDistance.x, 0);
        Utils::checkAllCollisions(Data::player, Data::ball);
    }

    // if it can't move altogether, try moving it by axis.
    if (!Pos::isClippingOutsideScreen(Data::player, playerPos + Vector2(0, moveDistance.y))) {
        playerPos += Vector2(0, moveDistance.y);
        Utils::checkAllCollisions(Data::player, Data::ball);
    }
}