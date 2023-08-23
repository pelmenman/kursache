#include "algo.h"
#include "./word/word.h"

int leveshtein(const Word& word, const Word& other) { return  min_distance(word, word.size(), other, other.size()); }

int min_distance(const Word& word, int size, const Word& other, int otherSize) {
    if (std::min(size, otherSize) == 0) return std::max(size, otherSize);

    int distance = word[size - 1] != other[otherSize - 1];

    int replacement = min_distance(word, size - 1, other, otherSize - 1) + distance;
    int deletion    = min_distance(word, size - 1, other, otherSize)     + 1;
    int insertion   = min_distance(word, size, other, otherSize - 1)     + 1;
    

    return min_cost(replacement, deletion, insertion);
}

int min_cost(int firstAction, int secondAction, int thirdAction) { return std::min(firstAction, std::min(secondAction, thirdAction)); }


std::vector<size_t> knuthMorrisPratt(Word& word) {
    std::vector<size_t> pi(word.size(), 0);

    for (int i = 1; i < word.size(); i++) {
        size_t j = pi[i - 1];

        while (j > 0 && word[j] != word[i]) {
            j = pi[j - 1];
        }

        pi[i] = (word[i] == word[j])? j + 1 : j;
    }

    return pi;
}