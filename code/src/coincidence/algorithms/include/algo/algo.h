#include <vector>
#include <functional>
#include <string>
#include <cmath>
#include "constants.h"

//int levenshtein(const Text::Word& word, const Text::Word& other);

////test it and then delete from header ?
//std::vector<size_t> prefix_fun(Text::Word& word);

//int knuthMorrisPratt(const Text::Word& word,const Text::Word& other);


// Спрашивает является подстрока префиксом
template<typename Str>
bool is_prefix(const Str& pattern, int start) {
    int j = 0;
    for(int i = start; i < pattern.size(); i++) {
        if(pattern[i] != pattern[j]) return false;
        ++j;
    }
    return true;
}

// Вычисялет максимальную длину подстроки начиная с start которая одновременно является суффиксом
template<typename Str>
int max_suffix_len(const Str& pattern, int start) {
    int len = 0;
    int i = start;
    int j = pattern.size() - 1;
    while(i >= 0 && pattern[i] == pattern[j]) {
        ++len;
        --i;
        --j;
    }
    return len;
}


// Вычисляет эврстику "хорошего" суффикса
template<typename Str>
std::vector<int> good_suffix(const Str& pattern) {
    int len = pattern.size();
    std::vector<int> table(len);

    int last_pref_pos = len;
    for(int i = len - 1; i >= 0; i--) {
        if(is_prefix(pattern, i + 1)) last_pref_pos = i + 1;
        table[len - 1 - i] = last_pref_pos - i + len - 1;
    }
    for(int i = 0; i < len - 1; i++) {
        int suff_len = max_suffix_len(pattern, i);
        table[suff_len] = len - 1 - i + suff_len;
    }

    return table;
}

// Вычисляет эвристику "плохого" символа
template<typename Str>
std::vector<int> bad_char(const Str& pattern) {
    int len = pattern.size();
    std::vector<int> table(26, len);

    for(int i = 0; i < len - 1; i++) {
        table[pattern[i] - 'a'] = len - 1 - i;
    }

    return table;
}

template<typename Pattern, typename Str>
void boyer_mur(const Pattern& pattern, const Str& str, const std::vector<int>& chars, const std::vector<int>& suffixes, const std::function<void(double ,int)>& supplier) {
    int pattern_len = pattern.size();
    int str_size = str.size();

    if(pattern_len == 0) return;

    for(int i = 0; i <= str_size - pattern_len; ) {
        int j = pattern_len - 1;
        while(pattern[j] == str[i + j]) {
            if(j == 0) {
                supplier(1.0, i);
                break;
            }
            --j;
        }
        i += chars[str[i + j] - 'a'];/*std::max(chars[str[i] - 'a'], suffixes[pattern_len - 1 - j]);*/
    }
}

template<typename Pattern, typename Str>
void knut_moris_pratt(const Pattern& pattern, const Str& str, const std::function<void(double, int)>& supplier) {
    int len = pattern.size() + 1 + str.size();
    auto concanated_index = [&str1 = pattern, &str2 = str](int index) {
        return index < str1.size() ? str1[index] :
               index == str1.size() ? '#' :
               str2[index - str1.size() - 1];
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
            supplier(1.0, i - 2*pattern.size()) :
            void();
    }
}

//требует от Pattern и Str иметь метод hash()
template<typename Pattern, typename Str>
void hashMask(const Pattern& pattern,
              const Str& str,
              const std::function<void(double, int)>& supplier,
              const std::function<double(const Pattern&, const Str&)>& percantage
              )
{
    unsigned int res = pattern.hash() & str.hash();
//    auto ones = [](unsigned int num){
//        num = num - ((num >> 1) & 0x55555555);
//        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
//        num = (num + (num >> 4)) & 0x0f0f0f0f;
//        num = num + (num >> 8);
//        num = num + (num >> 16);
//
//        return num & 0x0000003F;
//    }; // abd abc bad

//    auto perc = [&str1 = pattern, &str2 = str](){
//        int counter = 0;
//        for(int i = 0; i < std::min(str1.size(), str2.size()); i++) {
//            str1[i] == str2[i] ? counter++ : 0;
//        }
//        return counter;
//    };

//    if(res == str.hash()) {
//        int counter = eq(pattern, str);
//        if(counter/(str.size()) >= EQUAL_PERCANTAGE) supplier(counter/(str.size()));
//    }
    double perc = 0.0;
    (pattern.hash() & str.hash()) == str.hash() ?
        void() :
        ((perc = percantage(pattern, str)) >= EQUAL_PERCANTAGE ?
            supplier(perc ,str.pos()) :
            void());
}


//требует от Pattern и Str иметь метод hash()
template<typename Pattern, typename Str>
void hashEq(const Pattern& pattern,
             const Str& str,
             const std::function<void(double, int)>& supplier)
{
    pattern.hash() == str.hash() ?
        supplier(1.0, str.pos()) :
        void();
}

// слова длины < 18
template<typename >


