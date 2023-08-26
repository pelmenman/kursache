#include <text/text.h>
#include <vector>


int levenshtein(const Text::Word& word, const Text::Word& other);

//test it and then delete from header ?
std::vector<size_t> prefix_fun(Text::Word& word);

int knuthMorrisPratt(Text::Word& word, Text::Word& other);
