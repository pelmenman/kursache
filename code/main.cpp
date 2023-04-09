
#include "test/word/test_word.h"
#include "test/levenshtein/test_levenshtein.h"

void test() {
    testingWordClass();
    testingGetDistance();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test();
    return 0;
}
