#pragma once

class Levenshtein {
public:
    static Levenshtein getInstance();
    static getMinDistance(Word word, int sizeWord, Word otherWord, int sizeOtherWord);
private:
    Levenshtein();
    static inline Levenshtein* realization = nullptr;
};