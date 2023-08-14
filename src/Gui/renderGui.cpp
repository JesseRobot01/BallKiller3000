#include "../gui.h"
#include "../data.h"
#include "../gameHandler.h"
#include "version.h"
#include "raylib-cpp.hpp"

void Gui::renderGameGui() {


    raylib::DrawText("Lives: " + std::to_string(lives), 20, 10, 20, RED);
    raylib::DrawText("Score: " + std::to_string(score), 140, 10, 20, RED);
    raylib::DrawText("High: " + std::to_string(highScore), 260, 10, 20, RED);
    raylib::DrawText("Level: " + std::to_string(level), 380, 10, 20, RED);
    raylib::DrawText("v"  BALL_KILLER_VERSION, screenWidth - (std::string(BALL_KILLER_VERSION).length() * 5) - 10,
                     screenHeight - 15, 10, GRAY);


}


void Gui::renderGameContent() {
    // renders the balls, enemies and the player
    for (int b = 0; b < ballCount; ++b) {
        DrawCircleV(ballPos[b], ballSize[b], BLUE);
    }
    for (int e = 0; e < enemyCount; ++e) {
        DrawRectangleV(enemyPos[e], enemySize[e], YELLOW);


    }
    DrawCircleV(playerPos, playerSize, RED);
}

void Gui::renderGameOver() {
    // The game over screen

    raylib::DrawText("Game Over!!!", screenWidth / 2 - 3 * 60, screenHeight / 2 - 30, 60, RED);
    raylib::DrawText("Press enter to restart", screenWidth / 2 - 3 * 60 - 10, screenHeight / 2 + 30, 30, RED);
    if (IsKeyPressed(KEY_ENTER)) GameHandler::startGame();


    // draws a restart button
    raylib::Rectangle restartButton(screenWidth / 2 - MeasureText("Restart", 30) / 2 - 10, screenHeight / 2 + 65,
                                    MeasureText("Restart", 30) + 20, 50);
    DrawRectangleRec(restartButton, ColorAlpha(RED, 0.25));

    raylib::DrawText("Restart", screenWidth / 2 - MeasureText("Restart", 30) / 2, screenHeight / 2 + 75,
                     30, RED);

    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               restartButton)) {
        GameHandler::startGame();
    }
}

void Gui::renderStartScreen() {
    raylib::DrawText("BallKiller3000", screenWidth / 2 - MeasureText("BallKiller3000", 60) / 2, screenHeight / 2 - 50,
                     60, RED);
    raylib::DrawText("By JesseRobot01", screenWidth / 2 - MeasureText("By JesseRobot01", 15) / 2, screenHeight / 2 + 10,
                     15, GRAY);

    raylib::Rectangle playButton(screenWidth / 2 - MeasureText("Play", 30) / 2 - 10, screenHeight / 2 + 35,
                                 MeasureText("Play", 30) + 20, 50);

    DrawRectangleRec(playButton, ColorAlpha(RED, 0.25));

    raylib::DrawText("Play", screenWidth / 2 - MeasureText("Play", 30) / 2, screenHeight / 2 + 45,
                     30, RED);

    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               playButton)) {
        hasGameStarted = true;
        GameHandler::startGame();
    }
}


void Gui::renderControlStick() {
    if (IsGestureDetected(GESTURE_DRAG)) {
        if (!isTouchingScreen) {
            controlStickStartPos = GetMousePosition();
            isTouchingScreen = true;

            if (controlStickStartPos.CheckCollision(playerPos, 50)) isControlStickBasePlayer = true;
        }
        controlStickCurrentPos = controlStickStartPos.MoveTowards(GetMousePosition(), 50);

        if (!isControlStickBasePlayer) {
            controlStickCurrentPos = controlStickStartPos.MoveTowards(GetMousePosition(), 50);
            DrawCircleV(controlStickStartPos, 50, ColorAlpha(GRAY, 0.75));
            DrawCircleV(controlStickCurrentPos, 30, ColorAlpha(BLACK, 0.75));
        } else {
            controlStickStartPos = playerPos;
            controlStickCurrentPos = playerPos.MoveTowards(GetMousePosition(), 50);
            DrawCircleV(GetMousePosition(), 30, ColorAlpha(BLACK, 0.75));
        }
    } else {
        isTouchingScreen = false;
        isControlStickBasePlayer = false;
    }
}

void Gui::renderPauseMenu() {
    raylib::DrawText("Pause", screenWidth / 2 - MeasureText("Pause", 60) / 2, screenHeight / 2 - 50, 60, RED);

    raylib::Rectangle continueButton(screenWidth / 2 - MeasureText("Continue", 30) - 10,
                                     screenHeight / 2 + 35,
                                     MeasureText("Continue", 30) + 20, 50);

    raylib::Rectangle quitButton(screenWidth / 2 - 10 + 30,
                                 screenHeight / 2 + 35,
                                 MeasureText("Continue", 30) + 20, 50);

    raylib::DrawText("Continue", screenWidth / 2 - MeasureText("Continue", 30) / 2 - MeasureText("Continue", 30) / 2,
                     screenHeight / 2 + 45,
                     30, RED);

    raylib::DrawText("Quit", screenWidth / 2 - MeasureText("Quit", 30) / 2 + MeasureText("Continue", 30) / 2 + 30,
                     screenHeight / 2 + 45,
                     30, RED);

    DrawRectangleRec(continueButton, ColorAlpha(RED, 0.25));
    DrawRectangleRec(quitButton, ColorAlpha(RED, 0.25));

    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               continueButton)) {
        isGamePaused = false;
    }

    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               quitButton)) {
        CloseWindow();
    }

}