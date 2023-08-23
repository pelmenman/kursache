#include "test_knuth_morris_pratt.h"

void testKMP(Word word, std::vector<size_t>& expected_pi, int num_test) {
    std::vector<size_t> pi = knuthMorrisPratt(word);

    if (pi == expected_pi) {
        std::cout << "Test " << num_test << " passed: " << '\n';
    } else {
        std::cout << "Test " << num_test << "failed: " << '\n';
    }
    
    std::cout << "{ word = " << word << ", pi = [";
    std::copy(expected_pi.begin(), expected_pi.end(), std::ostream_iterator<size_t> (std::cout, ", "));
    std:: cout << "] }\n";
}


void testingKMP() {
    testKMP(Word("abacaba"), {0, 0, 1, 0, 1, 2, 3}, 1);
    testKMP(Word("a"), {0}, 2);
    testKMP(Word("abcdabeabf"), {0, 0, 0, 0, 1, 2, 0, 1, 2, 0}, 3);
}