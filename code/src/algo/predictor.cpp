#include <algo/predictor.h>

BasePredictor::BasePredictor(const std::string& pattern) //OK
    : _pattern(pattern)
{}

KnuthMorrisPrattPredictor::KnuthMorrisPrattPredictor(const std::string& pattern) //OK
    : BasePredictor(pattern)
{}

void
KnuthMorrisPrattPredictor::operator()(const Word &word) const { // OK
    _pattern.size() > word.size() ?
    void() :
    knuth_morris_pratt(_pattern, word, _supplier, word.pos());
}

HashMaskPredictor::HashMaskPredictor(const std::string& pattern) //OK
    : BasePredictor(pattern)
{
    _mask = mask_substr_hash(_pattern, _pattern.size());
}

void
HashMaskPredictor::operator()(const Word &word) const { //OK
    hash_mask(_pattern,
              word,
              _mask,
              word.hash(),
              _supplier,
              word.pos());
}

BoyerMoorePredictor::BoyerMoorePredictor(const std::string& pattern) //OK
    : BasePredictor(pattern)
{
    _bad_chars = std::move(bad_char(_pattern, ALPHABET_SIZE));
}

void
BoyerMoorePredictor::operator()(const Word &word) const { //OK
    return _pattern.size() > word.size() ?
           void() :
           boyer_moore(_pattern, word, _bad_chars, _supplier, word.pos());
}

LevenshteinPredictor::LevenshteinPredictor(const std::string& pattern) //OK
    : BasePredictor(pattern)
{}

void
LevenshteinPredictor::operator()(const Word &word) const { //OK
    levenshtein(_pattern, word, _supplier, word.pos());
}

WeakCodePredictor::WeakCodePredictor(const std::string& pattern) //OK
    : BasePredictor(pattern)
{}

void // weak code predictor
WeakCodePredictor::operator()(const Word &word) const { //OK
    return _pattern.size() > word.size() ?
           void() :
           knuth_morris_pratt(_pattern, word, _supplier, word.pos(), weak_code);
}

HashEqualPredictor::HashEqualPredictor(const std::string& pattern)
    : BasePredictor(pattern)
{
    _pattern_hash = poly_substr_hash(_pattern, _pattern.size());
}

void //weak hash + default hash
HashEqualPredictor::operator()(const Word &word) const {
    hash_eq(_pattern_hash, word.hash(), _supplier, word.pos());
}
