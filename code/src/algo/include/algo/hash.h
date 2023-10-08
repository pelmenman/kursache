#include <iostream>
#include <algo/encoders.h>


unsigned long long poly_substr_hash(
        const std::string& str,
        size_t _size,
        int _shift = 0);


unsigned int mask_substr_hash(
        const std::string& str,
        size_t _size,
        int _shift = 0);


unsigned long long poly_substr_weak_hash(
        const std::string& str,
        size_t _size,
        int _shift = 0);
