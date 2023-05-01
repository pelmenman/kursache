#include "Text.h"

Text::Text(std::string& text) {
    int wordCounter = 0;
    char* wordStart = &text[0];
    for(int i = 0; i < text.size(); i++) {
        if(isDivider(text[i]) || i == text.size() - 1) {
            if(!isDivider(*wordStart))
                words.push_back(new Word(wordStart,wordCounter));
            wordCounter = 0;
            wordStart = (&text[i]) + 1;
        }
        wordCounter++;
    }
}

int Text::getSize() const {
    return words.size();
}

bool Text::isDivider(char c) {
    return !isLower(c) && !isUpper(c);
}

const Word* Text::operator[](int i) const {
    return words[i];
}

Text::~Text() {
    for(auto word: words) {
        delete word;
    }
}

bool Text::isLower(char c) {
    return -1 < c - 'a' && c - 'a' < 34;
}

bool Text::isUpper(char c) {
    return -1 < c - 'A' && c - 'A' < 34;
}
