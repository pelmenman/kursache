#include <iostream>
#include <algo/encoders.h>

//template<typename Str>
unsigned long long poly_substr_hash(
        const std::string& str,
        size_t _size,
        int _shift = 0);

//template<typename Str>
unsigned int mask_substr_hash(
        const std::string& str,
        size_t _size,
        int _shift = 0);

//template<typename Str> //weak hash for сравнения // weak сравнения для неточного1
unsigned long long poly_substr_weak_hash(
        const std::string& str,
        size_t _size,
        int _shift = 0);
