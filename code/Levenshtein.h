#pragma once
#include "word/Word.h"

class Levenshtein {
public:
    static int getMinDistance(Word word, int sizeWord, Word otherWord, int sizeOtherWord);
private:
    Levenshtein();
};