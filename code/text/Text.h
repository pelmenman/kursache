#pragma once
#include "../word/Word.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

class Text {
public:
    Text(std::string& text);
    int getSize() const;
    const Word* operator[](int i) const;
    ~Text();
private:
    static bool isDivider(char c);
    static bool isLower(char c);
    static bool isUpper(char c);
    std::vector<const Word*> words;
};
