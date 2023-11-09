#include "../data.h"
#include "../gameHandler.h"
#include <iostream>

void Player::getMove() {
    if (isDead) return; // no need if he's ded

    if (isAi) {
        generateAIMove();
        return;
    }

    raylib::Vector2 moveTo;
    raylib::Vector2 output;


    //first check if there is a new or a removed touch

    if (knownTouchPoints != GetTouchPointCount()) {
        updateTouchPoints();
        knownTouchPoints = GetTouchPointCount();
    }

    // first get the touch screen touch points
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsGestureDetected(GESTURE_DRAG)) {
        //  now, check for the mouse
        output = getMouseMove();
        if (output != Vector2(0, 0))
            moveTo = output;
    } else if (GetTouchPointCount() > 1 && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        output = getTouchPointMove();
        if (output != Vector2(0, 0))
            moveTo = output;
    } else {
        isTouchingScreen = false;
        isUsingMouse = false;
    }

    // now keyboard
    output = getKeyboardMove();
    if (output != Vector2(0, 0))
        moveTo = output;

    move(moveTo);

    checkCollisionWithBalls();

}

raylib::Vector2 Player::getTouchPointMove() {
    raylib::Vector2 moveTo;
    if (touchPointIndex != -1) {
        if (!isTouchingScreen) {
            isTouchingScreen = true;
            if (dragEnabled)
                isControlStickBasePlayer = pos.CheckCollision(GetTouchPosition(touchPointIndex),
                                                              size + dragSensitivity);
            if (isControlStickBasePlayer) {
                controlStickStartPos = pos;
            } else {
                controlStickStartPos = GetTouchPosition(touchPointIndex);
            }
        }


        if (isControlStickBasePlayer) {
            controlStickStartPos = pos;

            controlStickCurrentPos = GetTouchPosition(touchPointIndex);
        } else {
            if (controlStickEnabled) {
                DrawCircleV(controlStickStartPos, 50, controlStickBaseColour);
                controlStickCurrentPos = controlStickStartPos.MoveTowards(GetTouchPosition(touchPointIndex), 50);
            } else {return 0;}
        }
        DrawCircleV(controlStickCurrentPos, 30, controlStickDragColour);

        moveTo = controlStickStartPos.MoveTowards(controlStickCurrentPos, speed) - controlStickStartPos;

        return moveTo;
    }


    return 0;

}

void Player::updateTouchPoints() {
    // first reset
    for (int p = 0; p < playerCount; ++p) {
        player[p].touchPointIndex = -1;
    }
    for (int t = 0; t < GetTouchPointCount(); ++t) {
        for (int p = 0; p < playerCount; ++p) {
            if (player[p].touchPointIndex == -1) {
                if (getWantedPlayer(GetTouchPosition(t)) == p) {
                    player[p].touchPointIndex = t;
                }
            }
        }

    }
}

raylib::Vector2 Player::getMouseMove() {
    raylib::Vector2 moveTo;

    // check if another player is using the mouse, because there can't be 2 mouses. and for touch screens there is a separate touch screen system.
    for (int p = 0; p < playerCount; ++p) {
        if (p != playerNumber) {
            if (player[p].isUsingMouse) return Vector2(0, 0);
        }
    }

    if (!isTouchingScreen) {

        // check if this is the wanted player
        if (getWantedPlayer(GetMousePosition()) != playerNumber) return 0;

        isTouchingScreen = true;
        isUsingMouse = true;
        if (dragEnabled)
            isControlStickBasePlayer = pos.CheckCollision(GetMousePosition(), size + dragSensitivity);

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
        if (controlStickEnabled) {
            DrawCircleV(controlStickStartPos, 50, controlStickBaseColour);
            controlStickCurrentPos = controlStickStartPos.MoveTowards(GetMousePosition(), 50);
        } else { return 0; }
    }
    DrawCircleV(controlStickCurrentPos, 30, controlStickDragColour);

    moveTo = controlStickStartPos.MoveTowards(controlStickCurrentPos, speed) - controlStickStartPos;

    return moveTo;
}


int Player::getWantedPlayer(raylib::Vector2 posToCheck) {
    // first drag.
    for (int p = 0; p < playerCount; ++p) {
        if (player[p].pos.CheckCollision(posToCheck, player[p].size + 30)) return p;
    }

    // now rect
    float recSize = screenWidth / (float) playerCount;
    for (int p = 0; p < playerCount; ++p) {
        raylib::Rectangle rectangle = Rectangle(recSize * (float) p, 0, recSize,
                                                screenHeight);

        if (rectangle.CheckCollision(posToCheck)) return p;

    }
    return -1;
}

raylib::Vector2 Player::getKeyboardMove() {
    // now, do the keyboard things.
    // first for two players
    raylib::Vector2 moveTo;

    if (playerNumber == 0) {
        if (IsKeyDown(KEY_W)) { moveTo.y = -speed; }
        if (IsKeyDown(KEY_A)) { moveTo.x = -speed; }
        if (IsKeyDown(KEY_S)) { moveTo.y = +speed; }
        if (IsKeyDown(KEY_D)) { moveTo.x = +speed; }
    }
    if (playerNumber == 1 || playerCount == 1) {
        if (IsKeyDown(KEY_UP)) { moveTo.y = -speed; }
        if (IsKeyDown(KEY_LEFT)) { moveTo.x = -speed; }
        if (IsKeyDown(KEY_DOWN)) { moveTo.y = +speed; }
        if (IsKeyDown(KEY_RIGHT)) { moveTo.x = +speed; }
    }

    return moveTo;

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
            checkCollisionWithBalls();
            return;
        } else {
            pos = pos.MoveTowards(pos + moveTo, speed);
            checkCollisionWithBalls();
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
            checkCollisionWithBalls();
            return;
        } else {
            pos = pos.MoveTowards(Vector2(pos.x + moveTo.x, pos.y), speed);
            checkCollisionWithBalls();
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
            checkCollisionWithBalls();
            pos = pos.MoveTowards(Vector2(pos.x, pos.y + moveTo.y), speed);
            return;
        } else {
            pos = pos.MoveTowards(Vector2(pos.x, pos.y + moveTo.y), speed);
            checkCollisionWithBalls();
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
