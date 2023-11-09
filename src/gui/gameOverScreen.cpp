#include "../data.h"
#include "../gui.h"
#include "../gameHandler.h"

void Gui::gameOver() {
    // Define button sizes
    raylib::Rectangle restartButton(screenWidth / 2 - (float) MeasureText("Restart", 30) - 10,
                                    screenHeight / 2 + 35,
                                    (float) MeasureText("Restart", 30) + 20, 50);

    raylib::Rectangle exitButton(screenWidth / 2 + 30 - 10,
                                 screenHeight / 2 + 35,
                                 (float) MeasureText("Restart", 30) + 20, 50);


    // Draw the elements
    // Draw the background
    DrawRectangle(0, 0, (int) screenWidth, (int) screenHeight, ColorAlpha(GRAY, 0.625));

    // Draw text
    raylib::DrawText("Game Over!!!", (int) screenWidth / 2 - MeasureText("Game Over!!!", 60) / 2,
                     (int) screenHeight / 2 - 50,
                     60, RED);
    raylib::DrawText("Press ENTER to restart!", (int) screenWidth / 2 - MeasureText("Press ENTER to restart!", 15) / 2,
                     (int) screenHeight / 2 + 10,
                     15, RED);

    DrawRectangleRec(restartButton, ColorAlpha(RED, 0.25));
    DrawRectangleRec(exitButton, ColorAlpha(RED, 0.25));

    raylib::DrawText("Restart",
                     (int) screenWidth / 2 - MeasureText("Restart", 30),
                     (int) screenHeight / 2 + 45,
                     30, RED);

    raylib::DrawText("Exit",
                     (int) screenWidth / 2 - MeasureText("Exit", 30) / 2 +
                     MeasureText("Restart", 30) / 2 + 30,
                     (int) screenHeight / 2 + 45,
                     30, RED);

    //handle buttons
    if (IsKeyPressed(KEY_ENTER)) GameHandler::startGame();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(),
                               restartButton)) {

        GameHandler::startGame(playerCount == 2);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(),
                               exitButton)) {
        isGameActive = false;
        frameCounter = 0; // Resets the counter to start a new AI game
    }

}