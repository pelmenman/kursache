#include "text.h"

Text::Text(std::string& text) {
    for(char* ptr = &text[0]; ptr != &text[0] + text.size(); ++ptr) {
        if (isSymb(*ptr)) {
            int word_size = 0;
            char* word_starts = ptr;
            for( ; ; ++ptr) {
                if(!isSymb(*ptr)) break;
                ++word_size;
            }
             words.push_back(Word(word_starts, word_size));
        }
    }
}

size_t Text::size() const { return words.size(); }

const Word& Text::operator[](int i) const { return words[i]; }

bool isSymb(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
