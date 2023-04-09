#pragma once
#include "Word.h"
#include <vector>

class Text {
public:
    Text(std::string text);
private:
    std::vector<Word> word;
};
