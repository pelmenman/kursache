#include "Text.h"

Text::Text(std::string text) {
    std::stringstream txt(text);
    std::string str;
    txt >> str;
    word.push_back(new Word(str));
}



