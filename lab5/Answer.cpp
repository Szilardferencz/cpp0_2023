//
// Created by Szilárd on 10/28/2023.
//

#include "Answer.h"

Answer::Answer(const std::string& text, bool correct) : text(text), correct(correct) {}

const std::string& Answer::getText() const {
    return text;
}

bool Answer::isCorrect() const {
    return correct;
}
