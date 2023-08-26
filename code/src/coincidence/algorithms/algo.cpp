#include <algo/algo.h>

int min_cost(int firstAction, int secondAction, int thirdAction) { return std::min(firstAction, std::min(secondAction, thirdAction)); }

int min_distance(const Text::Word& word, int size, const Text::Word& other, int otherSize) {
    if (std::min(size, otherSize) == 0) return std::max(size, otherSize);

    int distance = word[size - 1] != other[otherSize - 1];

    int replacement = min_distance(word, size - 1, other, otherSize - 1) + distance;
    int deletion    = min_distance(word, size - 1, other, otherSize)     + 1;
    int insertion   = min_distance(word, size, other, otherSize - 1)     + 1;
    

    return min_cost(replacement, deletion, insertion);
}

int leveshtein(const Text::Word& word, const Text::Word& other) { return  min_distance(word, word.size(), other, other.size()); }


std::vector<size_t> prefix_fun(const Text::Word& word) {
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

std::list<size_t> knuth_morris_pratt(const Text::Word& pattern, const Text::Word& word) {
    const std::vector<size_t> pi = prefix_fun(pattern);
    std::list<size_t> result;

    int i = 0;
    int j = 0;

    while (word.size() - i > pattern.size() - j) {
        if (j == pattern.size()) {
            result.push_back(j-i);
            j = pi[j - 1];
        }

        if (pattern[j] == word[i]) {
            i++;
            j++;
        } else if (pattern[j] != word[i] && j != 0) {
            j = pi[j - 1];
        } else {
            i++;
        }
    }

    return result;
}



void boyer_murr() {
    
}