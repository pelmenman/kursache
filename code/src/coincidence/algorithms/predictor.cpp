#include <algo/predictor.h>

void
KnutMorisPrattPredictor::operator()(const Text::Word& pattern, const Text::Word &word) const {
    //int pos = knuthMorrisPratt(pattern, word);
}

void
HashMaskPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {}

void
BoyerMurPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {
    boyer_mur(pattern, word, bad_chars, good_suffix, supplier);
}

void
LevenshteinPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {}

void
WeakHashPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {}

void
MetricPredictor::operator()(const Text::Word &pattern, const Text::Word &word) const {}
