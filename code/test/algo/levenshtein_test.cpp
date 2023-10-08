#include <coincidence/all.h>
#include <gtest/gtest.h>
#include <vector>

TEST(AlgoTests, LevenshteinTest) {
    //given
    const std::string pattern = "test";
    const std::string word = "text";
    std::vector<std::tuple<double, int>> coincidences;
    auto supplier = [&coincidences](double per, int pos) {
        coincidences.emplace_back(per, pos);
    };
    std::vector<std::tuple<double, int>> expected {
        std::make_tuple(0.75, 0),
    };

    //when
    levenshtein(pattern, word, supplier);

    //then
    ASSERT_EQ(coincidences, expected);
}

TEST(AlgoTests, LevenshteinTestOther) {
    //given
    const std::string pattern = "movie";
    const std::string word = "move";
    std::vector<std::tuple<double, int>> coincidences;
    auto supplier = [&coincidences](double per, int pos) {
        coincidences.emplace_back(per, pos);
    };

    std::vector<std::tuple<double, int>> expected {
        std::make_tuple(0.75, 0)
    };

    //when
    levenshtein(pattern, word, supplier);

    //then
    ASSERT_EQ(coincidences, expected);
}