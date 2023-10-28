//
// Created by Szilárd on 10/28/2023.
//

#ifndef LAB5_QUIZZ_H
#define LAB5_QUIZZ_H


#include <string>
#include <vector>
#include "Question.h"

class Quiz {
public:
    Quiz(const std::string& name, const std::vector<Question>& questions);
    const std::string& getName() const;
    const std::vector<Question>& getQuestions() const;
    static Quiz loadQuizFromFile(const std::string& filename);

private:
    std::string name;
    std::vector<Question> questions;
};


#endif //LAB5_QUIZZ_H
