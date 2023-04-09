//
// Created by chuch on 09.04.2023.
//
#include <iostream>
#include "../Word.cpp"

void testWord(std::string word, long long hash, int num_test) {
    auto w = Word(word);
    if(w.getHash() == hash)
        std::cout << "Test " << num_test << " passed: "<< '\n';
    else
        std::cout << "Test " << num_test << " failed: " << '\n';

    std::cout << '{' << "hash :" << hash << ", word :" << word << " }\n";
}

void testingWordClass() {
    testWord("aba", 1156, 1);
}