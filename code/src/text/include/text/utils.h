#include <vector>
#include <functional>
#include <string>

using hash_func = std::function<unsigned long long(const std::string&, size_t, int)>;

bool is_symb(char c);
