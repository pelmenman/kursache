#include <text/text.h>

Text::Text(std::shared_ptr<std::string> text,
           const hash_func& to_hash)
    : _text(text)
{
    int size;
    int shift;

    for(int i = 0; i < _text->size(); ++i) {
        if (is_symb(_text->operator[](i))) {
            size = 0;
            shift = i;
            for( ; is_symb(_text->operator[](i)); ++i) ++size;

            _words.emplace_back(_text, size, to_hash(*_text, size, shift), shift);
        }
    }
}

std::vector<Word>::iterator Text::begin() {
    return _words.begin();
}

std::vector<Word>::iterator Text::end() {
    return _words.end();
}

size_t Text::size() const { return _words.size(); }

const Word& Text::operator[](int i) const { return _words[i]; }
