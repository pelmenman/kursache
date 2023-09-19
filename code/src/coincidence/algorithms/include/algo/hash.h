#include <iostream>
#include <algo/constants.h>

unsigned int code(char c) { return islower(c) ? (c - 'a') + 1 : (c - 'A') + 1; }

unsigned int weak_code(char c) {

}

template<typename Str>
unsigned long long poly_substr_hash(const Str& str, int _shift, int _size) {
    unsigned long long _hash = 0;
    for (int i = 0; i < _size; ++i) {
        _hash = ((_hash + code(str[_shift + i]) * exp(i)) % MOD) % MOD;
    }

    return _hash;
}

template<typename Str>
unsigned int mask_substr_hash(const Str& str, int _shift, int _size) {
    unsigned int mask = 0;
    for(int i = 0;  i < _size; i++) {
        mask |= pows2[code(str[_shift + i]) - 1];
    }

    return mask;
}

template<typename Str> //weak hash for сравнения
unsigned int poly_substr_weak_hash(const Str& str, int _shift, int _size) { // weak сравнения для неточного1

}
