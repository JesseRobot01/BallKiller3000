#include "../data.h"
#include "../gameHandler.h"
#include <iostream>

void Player::getMove() {
    if (isDead) return; // no need if he's ded

    raylib::Vector2 moveTo;

    // first get the touch screen touch points
    if (GetTouchPointCount() > 0) {
//TODO For multi player on touch screens. still need to be planned how it will work.
    }
    // now, check for the mouse
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsGestureDetected(GESTURE_DRAG)) {
        if (!isTouchingScreen) {
            isTouchingScreen = true;
            isControlStickBasePlayer = pos.CheckCollision(GetMousePosition(), size + 30);
            if (isControlStickBasePlayer) {
                controlStickStartPos = pos;
            } else {
                controlStickStartPos = GetMousePosition();
            }
        }
        if (isControlStickBasePlayer) {
            controlStickStartPos = pos;
            controlStickCurrentPos = GetMousePosition();

        } else {
            DrawCircleV(controlStickStartPos, 50, controlStickBaseColour);
            controlStickCurrentPos = controlStickStartPos.MoveTowards(GetMousePosition(), 50);
        }
        DrawCircleV(controlStickCurrentPos, 30, controlStickDragColour);

        moveTo = controlStickStartPos.MoveTowards(controlStickCurrentPos, speed) - controlStickStartPos;


    } else {
        isTouchingScreen = false;
    }
    // now, do the keyboard things.
    // first for two players
    if (playerCount == 2) {
        if (playerNumber == 0) {
            if (IsKeyDown(KEY_W)) { moveTo.y -= speed; }
            if (IsKeyDown(KEY_A)) { moveTo.x -= speed; }
            if (IsKeyDown(KEY_S)) { moveTo.y += speed; }
            if (IsKeyDown(KEY_D)) { moveTo.x += speed; }
        }
        if (playerNumber == 1) {
            if (IsKeyDown(KEY_UP)) { moveTo.y -= speed; }
            if (IsKeyDown(KEY_LEFT)) { moveTo.x -= speed; }
            if (IsKeyDown(KEY_DOWN)) { moveTo.y += speed; }
            if (IsKeyDown(KEY_RIGHT)) { moveTo.x += speed; }
        }
    } else {
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) { moveTo.y -= speed; }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) { moveTo.x -= speed; }
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) { moveTo.y += speed; }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) { moveTo.x += speed; }
    }
    move(moveTo);
    checkCollisionWithBalls();

}

void Player::move(Vector2 moveTo) {
    // now move the player
    // make sure he stays inside.
    if (isInScreen(pos + moveTo)) {
        if (playerCount > 1) {
            // make future player
            Player futurePlayer;
            futurePlayer.playerNumber = playerNumber;
            futurePlayer.pos = pos.MoveTowards(pos + moveTo, speed);
            futurePlayer.size = size;

            for (int p = 0; p < playerCount; ++p) {
                if (futurePlayer.hasCollision(player[p])) {
                    // let's not trap him.
                    if (player[p].isInScreen(player[p].pos + moveTo))
                        player[p].pos = player[p].pos.MoveTowards(player[p].pos + moveTo, speed + 1);
                    else return;
                }
            }
            pos = pos.MoveTowards(pos + moveTo, speed);
            return;
        } else {
            pos = pos.MoveTowards(pos + moveTo, speed);
            return;
        }

    } else if (isInScreen(Vector2(pos.x + moveTo.x, pos.y))) {
        if (playerCount > 1) {
            // make future player
            Player futurePlayer;
            futurePlayer.playerNumber = playerNumber;
            futurePlayer.pos = pos.MoveTowards(Vector2(pos.x + moveTo.x, pos.y), speed);
            futurePlayer.size = size;

            for (int p = 0; p < playerCount; ++p) {
                if (futurePlayer.hasCollision(player[p])) {
                    // let's not trap him.
                    if (player[p].isInScreen(Vector2(player[p].pos.x + moveTo.x, player[p].pos.y)))
                        player[p].pos = player[p].pos.MoveTowards(Vector2(pos.x + moveTo.x, pos.y), speed + 1);
                    else return;
                }
            }
            pos = pos.MoveTowards(Vector2(pos.x + moveTo.x, pos.y), speed);
            return;
        } else {
            pos = pos.MoveTowards(Vector2(pos.x + moveTo.x, pos.y), speed);
            return;
        }
    } else if (isInScreen(Vector2(pos.x, pos.y + moveTo.y))) {
        if (playerCount > 1) {
            // make future player
            Player futurePlayer;
            futurePlayer.playerNumber = playerNumber;
            futurePlayer.pos = pos.MoveTowards(Vector2(pos.x, pos.y + moveTo.y), speed);
            futurePlayer.size = size;

            for (int p = 0; p < playerCount; ++p) {
                if (futurePlayer.hasCollision(player[p])) {
                    // let's not trap him.
                    if (player[p].isInScreen(Vector2(player[p].pos.x, player[p].pos.y + moveTo.y)))
                        player[p].pos = player[p].pos.MoveTowards(Vector2(pos.x, pos.y + moveTo.y), speed + 1);
                    else return;
                }
            }
            pos = pos.MoveTowards(Vector2(pos.x, pos.y + moveTo.y), speed);
            return;
        } else {
            pos = pos.MoveTowards(Vector2(pos.x, pos.y + moveTo.y), speed);
            return;
        }
    }
}

void Player::checkCollisionWithBalls() {
    for (int b = 0; b < ballCount; ++b) {
        if (hasCollision(ball[b])) {
            ball[b].isDead = true;
            score++;
            ballsInScreen--;
            if (ballsInScreen == 0) GameHandler::levelUp();
        }
    }
}