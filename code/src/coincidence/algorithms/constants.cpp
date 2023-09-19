#include <algo/constants.h>

static unsigned long long exp(int pow) {
    if(pow < vals.size()) return vals[pow];

    for(int i = vals.size(); i <= pow; i++) {
        vals.push_back((vals[i - 1] * ALPHABET_SIZE) % MOD);
    }

    return vals[pow];
}