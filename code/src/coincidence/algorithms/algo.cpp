#include <algo/algo.h>
#include <functional>

//int min_cost(int firstAction, int secondAction, int thirdAction) { return std::min(firstAction, std::min(secondAction, thirdAction)); }
//
//int min_distance(const Text::Word& word, int size, const Text::Word& other, int otherSize) {
//    if (std::min(size, otherSize) == 0) return std::max(size, otherSize);
//
//    int distance = word[size - 1] != other[otherSize - 1];
//
//    int replacement = min_distance(word, size - 1, other, otherSize - 1) + distance;
//    int deletion    = min_distance(word, size - 1, other, otherSize)     + 1;
//    int insertion   = min_distance(word, size, other, otherSize - 1)     + 1;
//
//
//    return min_cost(replacement, deletion, insertion);
//}
//
//int leveshtein(const Text::Word& word, const Text::Word& other) { return  min_distance(word, word.size(), other, other.size()); }
//
//
//std::vector<size_t> prefix_fun(Text::Word& word) {
//    std::vector<size_t> pi(word.size(), 0);
//
//    for (int i = 1; i < word.size(); i++) {
//        size_t j = pi[i - 1];
//
//        while (j > 0 && word[j] != word[i]) {
//            j = pi[j - 1];
//        }
//
//        pi[i] = (word[i] == word[j])? j + 1 : j;
//    }
//
//    return pi;
//}

//matchIndex: int or size_t?
// int knuthMorrisPratt(Text::Word& word, Text::Word& other) {
//     //TODO operator + for Words
//     std::vector<size_t> result = prefix_fun(word + '#' + other);
//     int matchIndex = -1;

//     for (int i = (word.size() +  1); i < result.size(); i++) {
//         if (result[i] == word.size()) {
//             matchIndex = i - word.size() + 1;
//             break;
//         }
//     }

//     return matchIndex;
// }

// Вычисляет эвристику "плохого" символа
//template<typename Str>
//std::vector<int> bad_char(const Str& pattern) {
//    int len = pattern.size();
//    std::vector<int> table(26, len);
//
//    for(int i = 0; i < len - 1; i++) {
//        table[pattern[i] - 'a'] = len - 1 - i;
//    }
//
//    return table;
//}

//// Спрашивает является подстрока префиксом
//template<typename Str>
//bool is_prefix(const Str& pattern, int start) {
//    int j = 0;
//    for(int i = start; i < pattern.size(); i++) {
//        if(pattern[i] != pattern[j]) return false;
//        ++j;
//    }
//    return true;
//}
//
//// Вычисялет максимальную длину подстроки начиная с start которая одновременно является суффиксом
//template<typename Str>
//int max_suffix_len(const Str& pattern, int start) {
//    int len = 0;
//    int i = start;
//    int j = pattern.size() - 1;
//    while(i >= 0 && pattern[i] == pattern[j]) {
//        ++len;
//        --i;
//        --j;
//    }
//    return len;
//}

//// Вычисляет эврстику "хорошего" суффикса
//template<typename Str>
//std::vector<int> good_suffix(const Str& pattern) {
//    int len = pattern.size();
//    std::vector<int> table(26, len);
//
//    int last_pref_pos = len;
//    for(int i = len - 1; i >= 0; i--) {
//        if(is_prefix(pattern, i + 1)) last_pref_pos = i + 1;
//        table[len - 1 - i] = last_pref_pos - i + len - 1;
//    }
//    for(int i = 0; i < len - 1; i++) {
//        int suff_len = max_suffix_len(pattern, i);
//        table[suff_len] = len - 1 - i + suff_len;
//    }
//
//    return table;
//}

//template<typename Pattern, typename Str>
//void boyer_mur(const Pattern& pattern, const Str& str, const std::vector<int>& chars, const std::vector<int>& suffixes, std::function<void(double ,int)> supplier) {
//    int pattern_len = pattern.size();
//    int str_size = str.size();
//
//    if(pattern_len == 0) return;
//
//    for(int i = pattern_len - 1; i < str_size; i++) {
//        int j = pattern_len - 1;
//        while(pattern[j] == str[i]) {
//            if(j == 0) supplier(1.0, i);
//            --i;
//            --j;
//        }
//        i += std::max(chars[pattern_len - 1 - j], suffixes[str[i] - 'a']);
//    }
//}