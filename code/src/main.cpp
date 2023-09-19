#include <iostream>
#include <vector>
#include <tuple>
#include "coincidence/algorithms/include/algo/constants.h"

void ui() {

}

void mark_up(std::string s, std::vector<std::tuple<double, int>> res, int size) {
    auto it = res.begin();
    for(int i = 0; i < s.size();) {
        if(std::get<1>(*it) == i) {
            std::cout << "\033[32m<";
            int ctr = size;
            while(ctr > 0) {
                 std::cout << s[i + size - ctr];
                 ctr--;
            }
            std::cout << ">\033[0m";
            ++it;
        }
        std::cout << s[i];
        i++;
    }
}

void init() {
    pows_two<32>::add_values(pows2);
    exp(30);
}

int main() {
    init();

    std::vector<std::tuple<double, int>> expected{
            std::make_tuple(1.0, 0),
            std::make_tuple(1.0, 10),
            std::make_tuple(1.0, 14),
            std::make_tuple(1.0, 18)
    };




    std::string text = "asdlkfjsdlasdfasdfasdaaahhjshdfaaa";
    mark_up(text, expected, 3);
    return 0;
}
