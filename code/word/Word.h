#pragma once
#include <string>
#include "../ENV.h"

class Word {
public:
    Word(char* word, int len);

    std::string getWord() const;
    long long getHash() const;
private:
    Word();
    long long hash = 0;
    char* word;
    int len;

    void hashIt();
    int getCode(char c) const;
};
