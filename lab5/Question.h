//
// Created by Szilárd on 10/28/2023.
//

#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H
#include <string>
#include <vector>
#include "Answer.h"

class Question {
public:
    Question(const std::string& text, const std::vector<Answer>& answers);
    const std::string& getText() const;
    const std::vector<Answer>& getAnswers() const;

private:
    std::string text;
    std::vector<Answer> answers;
};


#endif //LAB5_QUESTION_H
