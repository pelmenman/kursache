#include "test_prefix_fun.h"

void testPrefix(Word word, std::vector<size_t>& expected_pi, int num_test) {
    std::vector<size_t> pi = prefix_fun(word);

    if (pi == expected_pi) {
        std::cout << "Test " << num_test << " passed: " << '\n';
    } else {
        std::cout << "Test " << num_test << "failed: " << '\n';
    }
    
    std::cout << "{ word = " << word << ", pi = [";
    std::copy(expected_pi.begin(), expected_pi.end(), std::ostream_iterator<size_t> (std::cout, ", "));
    std:: cout << "] }\n";
}


void testingPrefix() {
    testPrefix(Word("abacaba"), {0, 0, 1, 0, 1, 2, 3}, 1);
    testPrefix(Word("a"), {0}, 2);
    testPrefix(Word("abcdabeabf"), {0, 0, 0, 0, 1, 2, 0, 1, 2, 0}, 3);
}