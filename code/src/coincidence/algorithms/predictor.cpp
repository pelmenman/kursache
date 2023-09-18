#include <algo/predictor.h>

void
KnutMorisPrattPredictor::operator()(const Text::Word& pattern, const Text::Word &word) const { // 2 hour
    return pattern.size() > word.size() ?
           void() :
           knut_moris_pratt(pattern, word, supplier);
}

void
HashMaskPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {} // 1 hour

void
BoyerMurPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {
    return pattern.size() > word.size() ?
           void() :
           boyer_mur(pattern, word, bad_chars, good_suffix, supplier);
}

void
LevenshteinPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {} // 1 hour

void
WeakHashPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {} // 1 hour

void
MetricPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {} // 1 hour

//hash aho - 1 hour

// с предобработкой - 1 hour
