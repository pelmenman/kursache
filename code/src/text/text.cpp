#include <text/text.h>

bool isSymb(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

Text::Text(std::string text): _text(std::move(text)) {
    for(int i = 0; i < _text.size(); ++i) {
        if (isSymb(_text[i])) {
            int word_size = 0;
            int word_starts = i;
            for( ; ; ++i) {
                if(!isSymb(_text[i])) break;
                ++word_size;
            }
            _words.emplace_back(word_size, word_starts, *this);
        }
    }
}

size_t Text::size() const { return _words.size(); }

const Text::Word& Text::operator[](int i) const { return _words[i]; }
