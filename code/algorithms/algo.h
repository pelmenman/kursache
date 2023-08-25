#include "../../word/Word.h"
#include <vector>


int levenshtein(const Word& word, const Word& other);

//test it and then delete from header ?
std::vector<size_t> prefix_fun(Word& word);

void knuthMorrisPratt(Word& word, Word& other);
