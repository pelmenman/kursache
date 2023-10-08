#include <algo/predictor.h>

BasePredictor::BasePredictor(std::string pattern) //OK
    : _pattern(std::move(pattern))
{}

KnutMorisPrattPredictor::KnutMorisPrattPredictor(std::string pattern) //OK
    : BasePredictor(std::move(pattern))
{}

void
KnutMorisPrattPredictor::operator()(const Word &word) const { // OK
    _pattern.size() > word.size() ?
           void() :
           knut_moris_pratt(_pattern, word, _supplier, word.pos());
}

HashMaskPredictor::HashMaskPredictor(std::string pattern) //OK
    : BasePredictor(std::move(pattern))
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

BoyerMurPredictor::BoyerMurPredictor(std::string pattern) //OK
    : BasePredictor(std::move(pattern))
{
    _bad_chars = std::move(bad_char(_pattern, ALPHABET_SIZE));
}

void
BoyerMurPredictor::operator()(const Word &word) const { //OK
    return _pattern.size() > word.size() ?
           void() :
           boyer_mur(_pattern, word, _bad_chars, _supplier, word.pos());
}

LevenshteinPredictor::LevenshteinPredictor(std::string pattern) //OK
    : BasePredictor(std::move(pattern))
{}

void
LevenshteinPredictor::operator()(const Word &word) const { //OK
    size_t sz_diff = _pattern.size() > word.size() ? _pattern.size() : word.size();
    return sz_diff > 2*_pattern.size() || sz_diff > 2*word.size() ?
            void() :
           levenshtein(_pattern, word, _supplier, word.pos());
}

WeakCodePredictor::WeakCodePredictor(std::string pattern) //OK
    : BasePredictor(std::move(pattern))
{}

void // weak code predictor
WeakCodePredictor::operator()(const Word &word) const { //OK
    return _pattern.size() > word.size() ?
           void() :
           knut_moris_pratt(_pattern, word, _supplier, word.pos(), weak_code);
}

HashEqualPredictor::HashEqualPredictor(std::string pattern)
    : BasePredictor(std::move(pattern))
{
    _pattern_hash = poly_substr_hash(_pattern, _pattern.size());
}

void //weak hash + default hash
HashEqualPredictor::operator()(const Word &word) const {
    hash_eq(_pattern_hash, word.hash(), _supplier, word.pos());
}
