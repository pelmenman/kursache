#include <algo/algo.h>

void hash_eq(unsigned long long pattern_hash,
             unsigned long long str_hash,
             const supplier& supplier,
             const int str_pos)
{
    pattern_hash == str_hash ?
        supplier(1.0, str_pos) :
        void();
}


