#include <text/text.h>
#include <text/utils.h>

Text::Text(std::shared_ptr<std::string> text, hash_func<std::string> to_hash)
    : _text(text)
{
    for(int i = 0; i < _text->size(); ++i) {
        if (is_symb(_text->operator[](i))) {
            int size = 0;
            int shift = i;
            for( ; ; ++i) {
                if(!is_symb(_text->operator[](i))) break;
                ++size;
            }
            _words.emplace_back(_text, size, to_hash(*_text, shift, size), shift);
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
