#include <iostream>
#include "raylib-cpp.hpp"
#include "../gui.h"
#include "../data.h"

void Gui::settings() {
    raylib::Rectangle closeButton(screenWidth - 80, 30, 50, 50);

    raylib::Rectangle controlStickToggleButton1(screenWidth / 2 + 60, 100, 50, 50);
    raylib::Rectangle controlStickToggleButton2(screenWidth / 2 + 180, 100, 50, 50);

    raylib::Rectangle dragToggleButton1(screenWidth / 2 + 60, 200, 50, 50);
    raylib::Rectangle dragToggleButton2(screenWidth / 2 + 180, 200, 50, 50);


    raylib::Rectangle sensitivityDecreaseButton(screenWidth / 2 + 60, 300, 50, 50);
    raylib::Rectangle sensitivityIncreaseButton(screenWidth / 2 + 180, 300, 50, 50);


    // draw background
    DrawRectangle(0, 0, (int) screenWidth, (int) screenHeight, ColorAlpha(GRAY, 0.625));

    // draw settings elements

    // control stick setting

    DrawRectangle(30, 100, (int) screenWidth / 2, 50, ColorAlpha(RED, 0.5));
    DrawRectangleRec(controlStickToggleButton1, ColorAlpha(RED, 0.25));
    DrawRectangle((int) screenWidth / 2 + 110, 100, 70, 50, ColorAlpha(RED, 0.5));
    DrawRectangleRec(controlStickToggleButton2, ColorAlpha(RED, 0.25));
    raylib::DrawText("Control stick enabled?",
                     30 + ((int) screenWidth / 2 - raylib::MeasureText("Control stick enabled?", 30)) / 2, 111, 30,
                     RED);

    raylib::DrawText("<", (int) screenWidth / 2 + 60 + (50 - raylib::MeasureText("<", 30)) / 2, 111, 30, RED);
    raylib::DrawText((controlStickEnabled ? "Yes" : "No"),
                     (int) screenWidth / 2 + 110 +
                     (70 - raylib::MeasureText((controlStickEnabled ? "Yes" : "No"), 30)) / 2,
                     111, 30, RED);
    raylib::DrawText(">", (int) screenWidth / 2 + 180 + (50 - raylib::MeasureText(">", 30)) / 2, 111, 30, RED);


    // Drag setting
    DrawRectangle(30, 200, (int) screenWidth / 2, 50, ColorAlpha(RED, 0.5));
    DrawRectangleRec(dragToggleButton1, ColorAlpha(RED, 0.25));
    DrawRectangle((int) screenWidth / 2 + 110, 200, 70, 50, ColorAlpha(RED, 0.5));
    DrawRectangleRec(dragToggleButton2, ColorAlpha(RED, 0.25));
    raylib::DrawText("Drag enabled?",
                     30 + ((int) screenWidth / 2 - raylib::MeasureText("Drag enabled?", 30)) / 2, 211, 30, RED);

    raylib::DrawText("<", (int) screenWidth / 2 + 60 + (50 - raylib::MeasureText("<", 30)) / 2, 211, 30, RED);
    raylib::DrawText((dragEnabled ? "Yes" : "No"),
                     (int) screenWidth / 2 + 110 + (70 - raylib::MeasureText((dragEnabled ? "Yes" : "No"), 30)) / 2,
                     211, 30, RED);
    raylib::DrawText(">", (int) screenWidth / 2 + 180 + (50 - raylib::MeasureText(">", 30)) / 2, 211, 30, RED);




    // Sensitivity setting
    if (dragEnabled) { // no need if drag is disabled.
        DrawRectangle(30, 300, (int) screenWidth / 2, 50, ColorAlpha(RED, 0.5));
        DrawRectangleRec(sensitivityDecreaseButton, ColorAlpha(RED, 0.25));
        DrawRectangle((int) screenWidth / 2 + 110, 300, 70, 50, ColorAlpha(RED, 0.5));
        DrawRectangleRec(sensitivityIncreaseButton, ColorAlpha(RED, 0.25));
        raylib::DrawText("Drag sensitivity",
                         30 + ((int) screenWidth / 2 - raylib::MeasureText("Drag sensitivity", 30)) / 2, 311, 30, RED);

        raylib::DrawText("<", (int) screenWidth / 2 + 60 + (50 - raylib::MeasureText("<", 30)) / 2, 311, 30, RED);

        raylib::DrawText(std::to_string((int) dragSensitivity),
                         (int) screenWidth / 2 + 110 +
                         (70 - raylib::MeasureText(std::to_string((int) dragSensitivity), 30)) / 2,
                         311, 30, RED);

        raylib::DrawText(">", (int) screenWidth / 2 + 180 + (50 - raylib::MeasureText(">", 30)) / 2, 311, 30, RED);
    }


    DrawRectangleRec(closeButton, ColorAlpha(RED, 0.25));
    raylib::DrawText("x", (int) screenWidth - 80 + (50 - raylib::MeasureText("x", 30)) / 2, 40, 30, RED);


    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        (CheckCollisionPointRec(GetMousePosition(), controlStickToggleButton1) ||
         CheckCollisionPointRec(GetMousePosition(), controlStickToggleButton2))) {
        controlStickEnabled = !controlStickEnabled;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (CheckCollisionPointRec(GetMousePosition(), dragToggleButton1) ||
                                                    CheckCollisionPointRec(GetMousePosition(), dragToggleButton2))) {
        dragEnabled = !dragEnabled;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), sensitivityDecreaseButton)) {
        if (dragSensitivity > 0)
            dragSensitivity--;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), sensitivityIncreaseButton)) {
        dragSensitivity++;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), closeButton)) {
        isSettingsPageShown = false;
    }
}