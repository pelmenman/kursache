#include <string>
#include "Word.h"

    Word::Word(char* word, int len) {
        this->word = word;
        this->len = len;
        hashIt();
    }

    Word::Word() {}

    std::string Word::getWord() const {
        char s[len];
        char* sWord = word;
        for(int i = 0; i < len; i++) {
            s[i] = *sWord;
            sWord++;
        }
        return s;
    }

    long long Word::getHash() const {
        return hash;
    }

    void Word::hashIt() {
        long long multiplication = 1;
        char* word_it = word;
        for (int i = 0; i < len; i++) {
            hash = (hash + getCode(*word_it) * multiplication % MODULE) % MODULE;
            multiplication = (multiplication * ALPHABET_SIZE) % MODULE;
            word_it++;
        }
    }

    int Word::getCode(char c) const {
            return islower(c) ? c - 'a' + 1 : c - 'A' + 1;
    }
