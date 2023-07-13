#ifndef BALL_KILLER_BALLS_H
#define BALL_KILLER_BALLS_H


class Balls {
public:
    static int generateBallPos(char axis);

    static void kill();

    static void push(int ballNum, int pushSteps, char axis);

    static bool isBallInScreen(int ballNum);
};


#endif
