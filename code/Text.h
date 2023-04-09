#pragma once
#include "Word.h"
#include <vector>
#include <string>
#include <sstream>

class Text {
public:
    Text(std::string text);
private:
    std::vector<Word*> word;
};
