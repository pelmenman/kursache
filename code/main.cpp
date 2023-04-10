
#include "test/word/test_word.h"
#include "test/levenshtein/test_levenshtein.h"
#include "test/text/test_text.h"

void test() {
    testingWordClass();
    testingGetDistance();
    testingTextClass();
}

int main() {
    test();
    return 0;
}
