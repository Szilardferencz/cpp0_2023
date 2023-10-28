//
// Created by Szilárd on 10/28/2023.
//

#include "Question.h"

Question::Question(const std::string& text, const std::vector<Answer>& answers) : text(text), answers(answers) {}

const std::string& Question::getText() const {
    return text;
}

const std::vector<Answer>& Question::getAnswers() const {
    return answers;
}