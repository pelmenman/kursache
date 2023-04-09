#include "test_levenshtein.h"

void testCreation() {
    auto p1 = Levenshtein::getInstance();
    auto p2 = Levenshtein::getInstance();

    if(p1 == p2) {
        std::cout << "Test creation instance passed";
        return;
    }

    std::cout << "Test creation instance failed";
}
