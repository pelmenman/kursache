#include <coincidence/all.h>
#include <gtest/gtest.h>
#include <vector>

TEST(AlgoTests, HashMaskTest) {
    //given
    const std::string pattern = "abcdefgrpu";
    const std::string word = "abcdefgrup";
    std::vector<std::tuple<double, int>> coincidences;
    auto supplier = [&coincidences](double per, int pos) {
        coincidences.emplace_back(per, pos);
    };
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(0.8, 0),
    };

    //when
    hash_mask(pattern, word, mask_substr_hash(pattern, 10), mask_substr_hash(word, 10), supplier);

    //then
    ASSERT_EQ(coincidences, expected);
}
