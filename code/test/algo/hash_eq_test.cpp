#include <coincidence/all.h>
#include <gtest/gtest.h>
#include <vector>

TEST(AlgoTests, HashEqualTest) {
    //given
    const std::string pattern = "abcdefgrpu";
    const std::string word = "abcdefgrpu";
    std::vector<std::tuple<double, int>> coincidences;
    auto supplier = [&coincidences](double per, int pos) {
        coincidences.emplace_back(per, pos);
    };
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(1.0, 0),
    };

    //when
    hash_eq(poly_substr_hash(pattern, 10), poly_substr_hash(word, 10), supplier);

    //then
    ASSERT_EQ(coincidences, expected);
}
