#include <string>
#include <text/word.h>

Word::Word(
        std::shared_ptr<std::string> text,
        size_t size,
        unsigned int hash_val,
        int pos)
        : _text(text),
          _size(size),
          _hash(hash_val),
          _pos(pos)
{}

size_t Word::size() const { return _size; }

unsigned long long Word::hash() const { return _hash; }

std::string Word::str() const {
    return _text->substr(_pos, _size);
}

char Word::operator[](size_t index) const { return _text->operator[](_pos + index); }

std::ostream& operator<<(std::ostream &os, const Word& word) {
    return os << word.str();
}

int Word::pos() const { return _pos; }
