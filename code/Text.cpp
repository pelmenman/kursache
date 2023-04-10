#include "Text.h"

Text::Text(std::string text) {
    if (text.empty()) return;

    auto punctuation = std::remove_if(text.begin(), text.end(), std::ispunct);
    text.erase(punctuation, text.end());

    std::stringstream txt(text);

    while (!txt.eof()) {
        std::string str;
        txt >> str;
        Text::words.push_back(new Word(str));
    } 
}

int Text::getSize() { return words.size(); }

Word Text::operator[](int i) { return *words[i];}
