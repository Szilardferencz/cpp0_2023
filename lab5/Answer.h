//
// Created by Szilárd on 10/28/2023.
//

#ifndef LAB5_ANSWER_H
#define LAB5_ANSWER_H
#include <string>

class Answer {
public:
    Answer(const std::string& text, bool correct);
    const std::string& getText() const;
    bool isCorrect() const;

private:
    std::string text;
    bool correct;
};


#endif //LAB5_ANSWER_H
