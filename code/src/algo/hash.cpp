#include <algo/hash.h>

unsigned long long poly_substr_weak_hash(
        const std::string& str,
        size_t _size,
        int _shift)
{
    unsigned long long _hash = 0;
    unsigned long long _exp = 1;
    for (int i = 0; i < _size; ++i) {
        _hash = (_hash + ( ( weak_code(str[_shift + i]) * _exp) % MOD) ) % MOD;
        _exp = ((_exp * WEAK_ALPHABET_SIZE) % MOD);
    }

    return _hash;
}

unsigned int mask_substr_hash(
        const std::string& str,
        size_t _size,
        int _shift)
{
    unsigned int mask = 0;
    for(int i = 0; i < _size; i++) mask |= (1 << (code(str[_shift + i]) - 1));

    return mask;
}

unsigned long long poly_substr_hash(
        const std::string& str,
        size_t _size,
        int _shift)
{
    unsigned long long _hash = 0;
    unsigned long long _exp = 1;
    for (int i = 0; i < _size; ++i) {
        _hash = (_hash + ( (code(str[_shift + i]) * _exp) % MOD) ) % MOD;
        _exp = (_exp * ALPHABET_SIZE) % MOD;
    }

    return _hash;
}