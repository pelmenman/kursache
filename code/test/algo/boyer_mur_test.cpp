#include <algo/algo.h>
#include <gtest/gtest.h>
#include <vector>

TEST(AlgoTests, BoyerMurTest) {
    //given
    std::string pattern = "asd";
    std::vector<std::tuple<double, int>> coincidences;
    auto supplier = [&coincidences](double per, int pos) {
        coincidences.emplace_back(per, pos);
    };
    std::string text = "asdlkfjsdlasdfasdfasdaaahhjshdfaaa";
    auto bad_chars = bad_char(pattern);
    auto good_suffixes = good_suffix(pattern);
    std::vector<std::tuple<double, int>> expected{
        std::make_tuple(1.0, 0),
        std::make_tuple(1.0, 10),
        std::make_tuple(1.0, 14),
        std::make_tuple(1.0, 18)
    };

    //when
    boyer_mur(pattern, text, bad_chars, good_suffixes, supplier);

    //then

    std::cout << "\033[32m" << "<your text goes here>" << "\033[0m";
    ASSERT_EQ(coincidences, expected);
}
