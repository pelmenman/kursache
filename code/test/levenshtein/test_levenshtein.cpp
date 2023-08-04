#include "test_levenshtein.h"

void testGetDistance(const Word& word1, const Word& word2, int expected_dist, int num_test) {
    int current_dist = levenshtein(word1, word2);

    if (current_dist == expected_dist) {
        std::cout << "Test " << num_test << " passed: " << '\n';
    } 
    else {
        std::cout << "Test " << num_test << "failed: " << '\n';
    }
        
    std::cout << "{ word1 = " << word1 << ", word2 = " << word2 << ", dist = " << expected_dist << " }" << '\n';
}

void testingGetDistance() {

    testGetDistance(Word("aaa"), Word("aaa"), 0, 1);
    testGetDistance(Word("kitten"), Word("sitting"), 3, 2);
    testGetDistance(Word("biba"), Word("boba"), 1, 3);
    testGetDistance(Word(""), Word("boba"), 4, 4);

}
