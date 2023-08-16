#include "../data.h"
#include "../pos.h"
#include "../utils.h"

void Pos::getPlayerMoveInput() {
    if (!isGameMultiPlayerGame) {
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
        if (isTouchingScreen[0]) {
            moveTo = controlStickStartPos.MoveTowards(controlStickCurrentPos, moveSpeed) - controlStickStartPos;
        }

        Pos::movePlayer(moveTo, 0);
    } else if (isGameMultiPlayerGame) {
        raylib::Vector2 moveTo[2];

        if (lives[0] > 0) {
            if (IsKeyDown(KEY_W)) { moveTo[0].y = -moveSpeed; }
            if (IsKeyDown(KEY_A)) { moveTo[0].x = -moveSpeed; }
            if (IsKeyDown(KEY_S)) { moveTo[0].y = moveSpeed; }
            if (IsKeyDown(KEY_D)) { moveTo[0].x = moveSpeed; }
        }

        if (lives[1] > 0) {
            if (IsKeyDown(KEY_UP)) { moveTo[1].y = -moveSpeed; }
            if (IsKeyDown(KEY_LEFT)) { moveTo[1].x = -moveSpeed; }
            if (IsKeyDown(KEY_DOWN)) { moveTo[1].y = moveSpeed; }
            if (IsKeyDown(KEY_RIGHT)) { moveTo[1].x = moveSpeed; }
        }

        Pos::movePlayer(moveTo[0], 0);
        Pos::movePlayer(moveTo[1], 1);
    }
}

void Pos::movePlayer(Vector2 moveDistance, int playerNum) {
    if (!Pos::isClippingOutsideScreen(Data::player, playerPos[playerNum] + moveDistance)) {
        playerPos[playerNum] += moveDistance;
        Utils::checkAllCollisions(Data::player, Data::ball);
        return;
    }

    // if it can't move altogether, try moving it by axis.
    if (!Pos::isClippingOutsideScreen(Data::player, playerPos[playerNum] + Vector2(moveDistance.x, 0))) {
        playerPos[playerNum] += Vector2(moveDistance.x, 0);
        Utils::checkAllCollisions(Data::player, Data::ball);
    }

    // if it can't move altogether, try moving it by axis.
    if (!Pos::isClippingOutsideScreen(Data::player, playerPos[playerNum] + Vector2(0, moveDistance.y))) {
        playerPos[playerNum] += Vector2(0, moveDistance.y);
        Utils::checkAllCollisions(Data::player, Data::ball);
    }
}