#include "Levenshtein.h"

int Levenshtein::getMinDistance(Word word, int sizeWord, Word otherWord, int sizeOtherWord) {
    if (std::min(sizeWord, sizeOtherWord) == 0) return std::max(sizeWord, sizeOtherWord);

    int distance = word.getWord()[sizeWord-1] == otherWord.getWord()[sizeOtherWord - 1] ? 0 : 1;

    int replacement = getMinDistance(word, sizeWord - 1, otherWord, sizeOtherWord - 1) + distance;
    int insertion = getMinDistance(word, sizeWord, otherWord, sizeOtherWord - 1) + 1;
    int deletion = getMinDistance(word, sizeWord - 1, otherWord, sizeOtherWord) + 1;

    return std::min(replacement, std::min(insertion, deletion));
}

Levenshtein::Levenshtein() {}
