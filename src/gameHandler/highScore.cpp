#include <fstream>
#include <sstream>
#include <iostream>
#include "../gameHandler.h"
#include "../data.h"
#include "version.h"

/**
    * Get the high score for single-player, multiplayer player one, or multiplayer player 2.
    *
    * @param multiPlayer Sets if it needs an multiplayer high score or a single-player high score.
    * @param playerIndexNumber The index number of the player, ignored if it is an single-player game.
    * The index number is the number the player has in the array. aka the playerNumber.
    * @return The high score.
    */
int GameHandler::getHigh(bool multiPlayer, int playerIndexNumber) {
    int highScoreSinglePlayer, highScoreMultiPlayer1, highScoreMultiPlayer2;
    std::string highScoreRaw;
    std::string highScoreSinglePlayerRAW, highScoreMultiPlayer1RAW, highScoreMultiPlayer2RAW;

#ifdef DEBUG
    std::ifstream highScoreFile("./highScore.txt");
#elif PLATFORM_WIN
    std::ifstream highScoreFile("%appdata%/BallKiller3000/highScore.txt"); // for windows
#else
    std::ifstream highScoreFile("./highScore.txt");
#endif

    if (highScoreFile) {

        highScoreFile >> highScoreRaw;

        // separate the different scores
        std::stringstream ss(highScoreRaw);


        try {
            getline(ss, highScoreSinglePlayerRAW, ',');
            getline(ss, highScoreMultiPlayer1RAW, ',');
            getline(ss, highScoreMultiPlayer2RAW, ',');

            highScoreSinglePlayer = stoi(highScoreSinglePlayerRAW);
            highScoreMultiPlayer1 = stoi(highScoreMultiPlayer1RAW);
            highScoreMultiPlayer2 = stoi(highScoreMultiPlayer2RAW);

        }


        catch (...) {
            std::cout << "ERROR: Failed to open high score.\n";
            return 0;
        }
        if (!multiPlayer) {
            return highScoreSinglePlayer;
        } else {
            if (playerIndexNumber == 0) { return highScoreMultiPlayer1; }
            else if (playerIndexNumber == 1) { return highScoreMultiPlayer2; }
        }

    } else {
        return 0;
    }

    return 0;
}

/**
 * Saves the highScore to its own file. <br>
 * WARNING!!! THIS OVERWRITES THE EXISTING HIGH SCORE. USE WITH CAUTION!!!
 * @param scoreToSave The score to save.
 * @param multiPlayer Sets if it saves an multiplayer high score or a single-player high score.
 * @param playerIndexNumber The index number of the player, ignored if it is an single-player game.
    * The index number is the number the player has in the array. aka the playerNumber.
 */
void GameHandler::saveHigh(int scoreToSave, bool multiPlayer, int playerIndexNumber) {
    std::string highScoreRaw;
    std::string highScoreSinglePlayerRAW = std::to_string(GameHandler::getHigh());
    std::string highScoreMultiPlayer1RAW = std::to_string(GameHandler::getHigh(true, 0));
    std::string highScoreMultiPlayer2RAW = std::to_string(GameHandler::getHigh(true, 1));

    // put the highScore in its corresponding string
    if (!multiPlayer) {
        highScoreSinglePlayerRAW = std::to_string(scoreToSave);
    } else {
        if (playerIndexNumber == 0) {
            highScoreMultiPlayer1RAW = std::to_string(scoreToSave);
        } else if (playerIndexNumber == 1) {
            highScoreMultiPlayer2RAW = std::to_string(scoreToSave);
        }
    }

    // assembles the highScores to one string
    highScoreRaw =
            highScoreSinglePlayerRAW + "," + highScoreMultiPlayer1RAW + "," + highScoreMultiPlayer2RAW + ",";

#ifdef DEBUG
    std::ofstream highScoreFile("./highScore.txt");
#elif PLATFORM_WIN
    std::ofstream  highScoreFile("%appdata%/BallKiller3000/highScore.txt"); // for windows
#else
    std::ofstream  highScoreFile("./highScore.txt");
#endif

    highScoreFile << highScoreRaw;
    highScoreFile.close();

}