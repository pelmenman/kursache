#include <iostream>
#include <algo/constants.h>

unsigned int code(char c);

unsigned int weak_code(char c);

template<typename Str>
unsigned long long poly_substr_hash(const Str& str, int _shift, int _size) {
    unsigned long long _hash = 0;
    for (int i = 0; i < _size; ++i) {
        _hash = (_hash + ((code(str[_shift + i]) * exp(ALPHABET_SIZE, i)) % MOD) ) % MOD;
    }

    return _hash;
}

template<typename Str>
unsigned int mask_substr_hash(const Str& str, int _shift, int _size) {
    unsigned int mask = 0;
    for(int i = 0;  i < _size; i++) {
        mask |= pows2[code(str[_shift + i])];
    }

    return mask;
}

template<typename Str> //weak hash for сравнения
unsigned long long poly_substr_weak_hash(const Str& str, int _shift, int _size) { // weak сравнения для неточного1
    unsigned long long _hash = 0;
    for (int i = 0; i < _size; ++i) {
        _hash = (_hash + ((weak_code(str[_shift + i]) * exp(WEAK_ALPHABET_SIZE, i)) % MOD) ) % MOD;
    }

    return _hash;
}
