#include <iostream>
#include "../data.h"
#include "../pos.h"
#include "../ball.h"
#include "../utils.h"

void Pos::getPlayerMoveInput() {

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        Pos::movePlayer(-moveSpeed, Data::y);
        Utils::checkAllCollisions(Data::player, Data::ball);
        Utils::checkAllCollisions(Data::player, Data::enemy);
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        Pos::movePlayer(moveSpeed, Data::y);
        Utils::checkAllCollisions(Data::player, Data::ball);
        Utils::checkAllCollisions(Data::player, Data::enemy);
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        Pos::movePlayer(-moveSpeed, Data::x);
        Utils::checkAllCollisions(Data::player, Data::ball);
        Utils::checkAllCollisions(Data::player, Data::enemy);
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        Pos::movePlayer(moveSpeed, Data::x);
        Utils::checkAllCollisions(Data::player, Data::ball);
        Utils::checkAllCollisions(Data::player, Data::enemy);
    }

}

void Pos::movePlayer(float moveDistance, Data::Axis axis) {

    switch (axis) {
        case Data::x:
            if (Pos::isPosInScreen(Vector2(playerPos.x + moveDistance, playerPos.y))) playerPos.x += moveDistance;
            break;

        case Data::y:
            if (Pos::isPosInScreen(Vector2(playerPos.x, playerPos.y + moveDistance))) playerPos.y += moveDistance;
            break;
    }

}