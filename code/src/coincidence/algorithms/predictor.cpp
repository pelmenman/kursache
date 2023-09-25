#include <algo/predictor.h>

BasePredictor::BasePredictor(std::string pattern)
    : _pattern(std::move(pattern))
{}

KnutMorisPrattPredictor::KnutMorisPrattPredictor(std::string pattern)
    : BasePredictor(std::move(pattern))
{}

void
KnutMorisPrattPredictor::operator()(const Word &word) const { // 2 hour
    return _pattern.size() > word.size() ?
           void() :
           knut_moris_pratt(_pattern, word, _supplier, code);
}

HashMaskPredictor::HashMaskPredictor(std::string pattern)
    : BasePredictor(std::move(pattern))
{
    _mask = mask_substr_hash(_pattern, 0, _pattern.size());
}

void
HashMaskPredictor::operator()(const Word &word) const {
    hash_mask(_pattern, word, _mask, word.hash(), word.pos(), _supplier);
}

BoyerMurPredictor::BoyerMurPredictor(std::string pattern)
    : BasePredictor(std::move(pattern))
{
    _bad_chars = std::move(bad_char(pattern, code, ALPHABET_SIZE));
}

void
BoyerMurPredictor::operator()(const Word &word) const {
    return _pattern.size() > word.size() ?
           void() :
           boyer_mur(_pattern, word, _bad_chars, _supplier, code);
}

LevenshteinPredictor::LevenshteinPredictor(std::string pattern)
    : BasePredictor(std::move(pattern))
{}

void
LevenshteinPredictor::operator()(const Word &word) const {
    int sz_diff = _pattern.size() > word.size() ? _pattern.size() : word.size();
    return sz_diff > _pattern.size() || sz_diff > word.size() ?
            void() :
           levenshtein(_pattern, word, _supplier);
}

WeakCodePredictor::WeakCodePredictor(std::string pattern)
    : BasePredictor(std::move(pattern))
{}

void // weak code predictor
WeakCodePredictor::operator()(const Word &word) const {
    return _pattern.size() > word.size() ?
           void() :
           knut_moris_pratt(_pattern, word, _supplier, weak_code);
}

HashEqualPredictor::HashEqualPredictor(std::string pattern)
    : BasePredictor(std::move(pattern))
{
    _pattern_hash = poly_substr_hash(_pattern, 0, _pattern.size());
}

void //weak hash + default hash
HashEqualPredictor::operator()(const Word &word) const {
    hash_eq(_pattern_hash, word.hash(), word.pos(), _supplier);
}

//hash aho - 1 hour
