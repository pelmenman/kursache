#include "Levenshtein.h"

Levenshtein Levenshtein::getInstance() {
    if(realization == 0) {
        realization = new Levenshtein();
        return *realization;
    }
    return *realization;
}

Levenshtein::Levenshtein() {}
