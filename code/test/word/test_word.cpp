
#include "test_word.h"

void testWord(std::string word, long long hash, int num_test) {
    auto w = Word(&word[0], word.size());
    if(w.getHash() == hash)
        std::cout << "Test " << num_test << " passed: "<< '\n';
    else
        std::cout << "Test " << num_test << " failed: " << '\n';

    std::cout << "Expect: " << "{ " << "hash: " << hash << ", word: " << word << " }\n";
    std::cout << "Result: " << "{ " << "hash: " << w.getHash() << ", word: " << w.getWord() << " }\n";
}

void testingWordClass() {
    testWord("aaa", 1123, 1);
    testWord("Hello", 123, 2);
}