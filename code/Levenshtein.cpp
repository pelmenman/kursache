#include "Levenshtein.h"

Levenshtein* Levenshtein::getInstance() {
    if(realization != nullptr) {
        return realization;
    }
    realization = new Levenshtein();
    return realization;
}

Levenshtein::Levenshtein() {}
