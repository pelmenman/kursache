#include <string>
#include "word.h"
#include "../constants.h

    Word::Word(char* word, size_t size): word(word), size(size) { hashing(); } 
    
    Word::Word(const std::string& str): word(str), size(str.size()) { hashing(); }

    size_t Word::size() const { return size; }

    long long Word::hash() const { return hash; }

    void Word::hashing() {
        long long exp = 1;
        for (char* ptr = word; ptr != word + size; ptr++) {
            hash = ((hash + code(*ptr) * exp) % MOD) % MOD;
            exp = (exp * ALPHABET_SIZE) % MOD;
        }
    }

    char Word::operator[](size_t index) const { return *(word + index); }

    int code(char c) const { return islower(c) ? c - 'a' + 1 : c - 'A' + 1; }

    std::ostream& operator<<(std::ostream &os, const Word& word) {
        for(char* ptr = word; ptr != word + size; ptr++) {
            os << *ptr;
        }
    }
