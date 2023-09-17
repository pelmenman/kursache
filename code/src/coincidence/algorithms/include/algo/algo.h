#include <vector>
#include <functional>

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

}



int hashMask();


