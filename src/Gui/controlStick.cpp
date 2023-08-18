#include "../gui.h"
#include "../data.h"
#include "raylib-cpp.hpp"

void Gui::renderControlStick() {
    if (!isGameMultiPlayerGame) {
        if (IsGestureDetected(GESTURE_DRAG)) {
            if (!isTouchingScreen[0]) {
                controlStickStartPos[0] = GetMousePosition();
                isTouchingScreen[0] = true;

                if (controlStickStartPos[0].CheckCollision(playerPos[0], 50)) isControlStickBasePlayer = true;
            }
            controlStickCurrentPos[0] = controlStickStartPos[0].MoveTowards(GetMousePosition(), 50);

            if (!isControlStickBasePlayer) {
                controlStickCurrentPos[0] = controlStickStartPos[0].MoveTowards(GetMousePosition(), 50);
                DrawCircleV(controlStickStartPos[0], 50, ColorAlpha(GRAY, 0.75));
                DrawCircleV(controlStickCurrentPos[0], 30, ColorAlpha(BLACK, 0.75));
            } else {
                controlStickStartPos[0] = playerPos[0];
                controlStickCurrentPos[0] = playerPos[0].MoveTowards(GetMousePosition(), 50);
                DrawCircleV(GetMousePosition(), 30, ColorAlpha(BLACK, 0.75));
            }
        } else {
            isTouchingScreen[0] = false;
            isControlStickBasePlayer = false;
        }
    } else {
        // for the mouse
        if (IsGestureDetected(GESTURE_DRAG)) {
            for (int p = 0; p <= 1; ++p) {
                raylib::Vector2 mousePosition = GetMousePosition(); // needed to convert the old vector2 into cpp vector 2

                if (!isTouchingScreen[0] && !isTouchingScreen[1]) {
                    // Get which player is touching the screen;
                    if (mousePosition.CheckCollision(playerPos[p], 50)) isTouchingScreen[p] = true;
                }

                if (isTouchingScreen[p]) {

                    controlStickStartPos[p] = playerPos[p];
                    controlStickCurrentPos[p] = playerPos[p].MoveTowards(GetMousePosition(), 50);


                    // draw control point
                    if (p == 0)
                        DrawCircleV(GetMousePosition(), 30, ColorAlpha(RED, 0.75));
                    if (p == 1)
                        DrawCircleV(GetMousePosition(), 30, ColorAlpha(GREEN, 0.75));
                }
            }
        } else {
            isTouchingScreen[0] = false;
            isTouchingScreen[1] = false;
        }
    }
}