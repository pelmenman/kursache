#pragma once
#include "Word.h"
#include <vector>
#include <string>
#include <fstream>

class Text {
public:
    Text(std::string text);
    Text(std::ifstream text);

    void next();
private:
    static const int bunch = 100;
    static int start;
    std::string text;
    std::ifstream text_file;
    std::vector<Word> word;
};
