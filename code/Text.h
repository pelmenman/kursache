#pragma once
#include "Word.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

class Text {
public:
    Text(std::string text);
    int getSize();
    Word operator[](int i);
private:
    std::vector<Word*> words;
};
