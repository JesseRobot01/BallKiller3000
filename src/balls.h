#ifndef BALL_KILLER_BALLS_H
#define BALL_KILLER_BALLS_H


class Balls {
public:
    int generateBallPos(char axis);

    void kill();

    void push(int ballNum, int pushSteps, char axis);

    bool isBallInScreen(int num, int steps, char axis);
};


#endif
