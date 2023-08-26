#include <string>
#include <text/text.h>
#include <text/constants.h>

Text::Word::Word(size_t _size, int _pos, const Text& _from)
                : _size(_size), _pos(_pos), _from(_from)
{
    hashing();
}

size_t Text::Word::size() const { return _size; }

unsigned long long Text::Word::hash() const { return _hash; }

std::string Text::Word::str() const {
    return _from._text.substr(_pos, _size);
}

unsigned int code(char c) { return islower(c) ? (c - 'a') + 1 : (c - 'A') + 1; }

void Text::Word::hashing() {
    unsigned long long exp = 1;
    _hash = 0;
    for (int i = 0; i < _size; ++i) {
        _hash = ((_hash + code(_from._text[_pos + i]) * exp) % MOD) % MOD;
        exp = (exp * ALPHABET_SIZE) % MOD;
    }
}

char Text::Word::operator[](size_t index) const { return _from._text[_pos + index]; }

std::ostream& operator<<(std::ostream &os, const Text::Word& word) {
    return os << word.str();
}
