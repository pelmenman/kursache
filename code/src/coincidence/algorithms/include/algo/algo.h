#include <text/text.h>
#include <vector>
#include <list>
#include <array>

int levenshtein(const Text::Word& word, const Text::Word& other);

std::list<size_t> knuth_morris_pratt(Text::Word& word, Text::Word& other);
