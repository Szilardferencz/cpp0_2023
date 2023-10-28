//
// Created by Szilárd on 10/28/2023.
//

#ifndef LAB5_QUIZZGAME_H
#define LAB5_QUIZZGAME_H
#include "Quizz.h"

class QuizGame {
public:
    QuizGame(const Quiz& quiz);
    void startGame();

private:
    const Quiz quiz;
    int score;

    void displayQuestion(const Question& question);
    void collectAnswers(const Question& question);
};


#endif //LAB5_QUIZZGAME_H
