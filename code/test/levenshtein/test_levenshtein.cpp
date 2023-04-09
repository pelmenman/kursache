#include "test_levenshtein.h"

void testGetDistance(Word word1, Word word2, int dist, int num_test) {
    int current_dist = Levenshtein::getMinDistance(word1,word1.getWord().size(), word2, word2.getWord().size());

    if (current_dist == dist) {
        std::cout << "Test " << num_test << " passed: " << '\n';
    } else {
        std::cout << "Test " << num_test << "failed: " << '\n';
    }
    std::cout << "{ word1 = " << word1.getWord() << ", word2 = " << word2.getWord() << ", dist = " << dist << " }" << '\n';
}

void testingGetDistance() {
    testGetDistance(Word("aaa"), Word("aaa"), 0, 1);
    testGetDistance(Word("kitten"), Word("sitting"), 3, 2);
    testGetDistance(Word("biba"), Word("boba"), 1, 3);
    testGetDistance(Word(""), Word("boba"), 4, 4);

}
