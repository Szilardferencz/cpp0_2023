//
// Created by Szilárd on 10/28/2023.
//

#include "Quizz.h"
#include <fstream>
#include <sstream>

Quiz::Quiz(const std::string& name, const std::vector<Question>& questions) : name(name), questions(questions) {}

const std::string& Quiz::getName() const {
    return name;
}

const std::vector<Question>& Quiz::getQuestions() const {
    return questions;
}