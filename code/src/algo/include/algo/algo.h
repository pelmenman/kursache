#include <vector>
#include <functional>
#include <string>
#include <cmath>
#include <algo/hash.h>

using supplier = std::function<void(double ,int)>;
using encoder = std::function<unsigned int(char)>;
using percentager = std::function<double(int, int)>;
using table = std::vector<std::vector<int>>;

template<typename Pattern, typename Str>
void knut_moris_pratt(const Pattern& pattern,
                      const Str& str,
                      const supplier& supplier,
                      const int str_pos = 0,
                      const encoder& encoder = code)
{
    int len = pattern.size() + 1 + str.size();
    auto concanated_index = [&str1 = pattern, &str2 = str, &coder = encoder](int index) {
        return index < str1.size() ? coder(str1[index]) :
               index == str1.size() ? '#' :
               coder(str2[index - str1.size() - 1]);
    };


    std::vector<int> prefix_table(len);
    for(int i = 1; i < len; ++i) {
        int j = prefix_table[i - 1];
        while(j > 0 && concanated_index(i) != concanated_index(j)) {
            j = prefix_table[j - 1];
        }
        if(concanated_index(i) == concanated_index(j)) ++j;
        prefix_table[i] = j;
    }

    for(int i = pattern.size(); i < len + 1; i++) {
        prefix_table[i] == pattern.size() ?
        supplier(1.0, str_pos + (i - 2*pattern.size())) :
        void();
    }
}

template<typename Pattern, typename Str>
void hash_mask(const Pattern& pattern,
               const Str& str,
               unsigned int pattern_mask,
               unsigned int str_mask,
               const supplier& supplier,
               const int str_pos = 0)
{
//    unsigned int res = _pattern.hash() & str.hash();
//    auto ones = [](unsigned int num){
//        num = num - ((num >> 1) & 0x55555555);
//        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
//        num = (num + (num >> 4)) & 0x0f0f0f0f;
//        num = num + (num >> 8);
//        num = num + (num >> 16);
//
//        return num & 0x0000003F;
//    };

    auto percent = [&str1 = pattern, &str2 = str]() {
        int counter = 0;
        for (int i = 0; i < std::min(str1.size(), str2.size()); i++) {
            str1[i] == str2[i] ? counter++ : 0;
        }
        return ((double)counter) / std::max(str1.size(), str2.size());
    };

    double perc = 0.0;
    (pattern_mask & str_mask) >= pattern_mask ?
        ((perc = percent()) >= EQUAL_PERCENTAGE ?
            supplier(perc ,str_pos) :
            void()) :
    void();
}

// Вычисляет эвристику "плохого" символа
template<typename Str>
std::vector<int> bad_char(const Str& pattern,
                          int alph_size,
                          const encoder& encoder = code)
{
    int len = pattern.size();
    std::vector<int> table(alph_size, len);

    for(int i = 0; i < len - 1; i++) {
        table[encoder(pattern[i])] = len - 1 - i;
    }

    return table;
}

template<typename Pattern, typename Str>
void boyer_mur(const Pattern& pattern,
               const Str& str,
               const std::vector<int>& chars,
               const supplier& supplier,
               const int str_pos = 0,
               const encoder& encoder = code)
{
    int pattern_len = pattern.size();
    int str_size = str.size();

    if(pattern_len == 0) return;

    for(int i = 0; i <= str_size - pattern_len; ) {
        int j = pattern_len - 1;
        while(encoder(pattern[j]) == encoder(str[i + j])) {
            if(j == 0) {
                supplier(1.0, str_pos + i);
                break;
            }
            --j;
        }
        i += chars[encoder(str[i + j])];
    }
}

template<typename Pattern, typename Str>
void dist(const Pattern& pattern,
          const Str& str,
          table& table,
          const percentager& percentager,
          const supplier& supplier,
          const int str_pos = 0,
          const encoder& encoder = code)
{
    int curr_row = 0;
    int prev_row;
    int len_p = pattern.size();
    int len_s = str.size();

    for(int i = 1; i < len_p + 1; i++) { // p -> m str2, s -> n str1
        prev_row = curr_row;
        curr_row = (curr_row + 1) % 2;
        table[curr_row][0] = table[prev_row][0] + 1;

        int min_on_row = len_s;
        for(int j = 1; j < len_s + 1; j++) {
            int add = table[prev_row][j] + 1;
            int del = table[curr_row][j - 1] + 1;
            int repl = table[prev_row][j - 1];
            repl += (encoder(pattern[i - 1]) != encoder(str[j - 1]) ? 1 : 0);

            table[curr_row][j] = std::min(std::min(add, del), repl);
            min_on_row = std::min(min_on_row, table[curr_row][j]);
        }

        if(percentager(min_on_row, len_s) > 1.0 - EQUAL_PERCENTAGE) return;
    }

    double diff = percentager(table[curr_row][len_s], len_s);
    diff < 1.0 - EQUAL_PERCENTAGE ?
        supplier(1.0 - diff, str_pos) :
        void();
}

template<typename Pattern, typename Str>
void levenshtein(const Pattern& pattern,
                 const Str& str,
                 const supplier& supplier,
                 const int str_pos = 0,
                 const encoder& encoder = code) {
    int len_s = str.size();
    table table(2, std::vector<int>(len_s + 1, 0));

    for(int i = 1; i < len_s + 1; i++) table[0][i] = i;

    auto percent = [](int diff, int sz) {
        return ((double)diff) / sz;
    };

    dist(pattern, str, table, percent, supplier, str_pos, encoder);
}


//требует от Pattern и Str -> также для weak hash
void hash_eq(unsigned long long pattern_hash,
             unsigned long long str_hash,
             const supplier& supplier,
             const int str_pos = 0);



