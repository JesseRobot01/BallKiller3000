#ifndef BALLKILLER3000_GAMEHANDLER_H
#define BALLKILLER3000_GAMEHANDLER_H

class GameHandler {
public:
    static void startGame(int playerCount = 1, bool isAiGame = false);

    static void levelUp();


    /**
     * Get the high score for single-player, multiplayer player one, or multiplayer player 2.
     *
     * @param multiPlayer Sets if it needs an multiplayer high score or a single-player high score.
     * @param playerIndexNumber The index number of the player, ignored if it is an single-player game.
     * The index number is the number the player has in the array. aka the playerNumber.
     * @return The high score.
     */
    static int getHigh(bool multiPlayer = false, int playerIndexNumber = -1);

    /**
    * Saves the highScore to its own file. <br>
            * WARNING!!! THIS OVERWRITES THE EXISTING HIGH SCORE. USE WITH CAUTION!!!
    * @param scoreToSave The score to save.
    * @param multiPlayer Sets if it saves an multiplayer high score or a single-player high score.
    * @param playerIndexNumber The index number of the player, ignored if it is an single-player game.
    * The index number is the number the player has in the array. aka the playerNumber.
    */

    static void saveHigh(int scoreToSave, bool multiPlayer = false, int playerIndexNumber = -1);
};

#endif
