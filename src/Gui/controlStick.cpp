#include "../gui.h"
#include "../data.h"
#include "raylib-cpp.hpp"

void Gui::renderControlStick() {
    if (!isGameMultiPlayerGame) {
        if (IsGestureDetected(GESTURE_DRAG)) {
            if (!isTouchingScreen[0]) {
                controlStickStartPos = GetMousePosition();
                isTouchingScreen[0] = true;

                if (controlStickStartPos.CheckCollision(playerPos[0], 50)) isControlStickBasePlayer = true;
            }
            controlStickCurrentPos = controlStickStartPos.MoveTowards(GetMousePosition(), 50);

            if (!isControlStickBasePlayer) {
                controlStickCurrentPos = controlStickStartPos.MoveTowards(GetMousePosition(), 50);
                DrawCircleV(controlStickStartPos, 50, ColorAlpha(GRAY, 0.75));
                DrawCircleV(controlStickCurrentPos, 30, ColorAlpha(BLACK, 0.75));
            } else {
                controlStickStartPos = playerPos[0];
                controlStickCurrentPos = playerPos[0].MoveTowards(GetMousePosition(), 50);
                DrawCircleV(GetMousePosition(), 30, ColorAlpha(BLACK, 0.75));
            }
        } else {
            isTouchingScreen[0] = false;
            isControlStickBasePlayer = false;
        }
    }
}