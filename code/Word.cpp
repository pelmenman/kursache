#include <string>
#include "Word.h"

    Word::Word(std::string& word) {
        this->word = word;
        hashIt();
    }

    std::string Word::getWord() const {
        return this->word;
    }

    long long Word::getHash() const {
        return this->hash;
    }

    void Word::hashIt() {
        long long sub = 1;
        for (auto symb : word) {
            hash = (hash + (symb - 'a' + 1) * sub % MODULE) % MODULE;
            sub *= ALPHABET_SIZE;
        }
    }
