#include "Levenshtein.h"

Levenshtein* Levenshtein::getInstance() {
    if(realization != nullptr) {
        return realization;
    }
    realization = new Levenshtein();
    return realization;
}

int Levenshtein:: getMinDistance(Word word, int sizeWord, Word otherWord, int sizeOtherWord) {
    if (min(sizeWord, sizeOtherWord) == 0) return max(sizeWord, sizeOtherWord);

    int distance;

    (word[sizeWord-1] == otherWord[sizeOtherWord - 1])? distance = 0 : distance = 1;

    return min(getMinDistance(word, sizeWord - 1, otherWord, sizeOtherWord - 1) + distance, 
           min(getMinDistance(word, sizeWord, otherWord, sizeOtherWord - 1) + 1, 
           getMinDistance(word, sizeWord - 1, otherWord, sizeOtherWord) + 1));

}

Levenshtein::Levenshtein() {}
