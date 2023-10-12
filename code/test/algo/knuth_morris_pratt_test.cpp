#include <coincidence/all.h>
#include <gtest/gtest.h>

TEST(AlgoTests, KMPTest) {
    //given
    std::string pattern = "asd";
    std::vector<std::tuple<double, int>> coincidences;
    auto supplier = [&coincidences](double per, int pos) {
        coincidences.emplace_back(per, pos);
    };
    std::string text = "asdlkfjsdlasdfasdfasdaaahhjshdfaaa";
    std::vector<std::tuple<double, int>> expected{
            std::make_tuple(1.0, 0),
            std::make_tuple(1.0, 10),
            std::make_tuple(1.0, 14),
            std::make_tuple(1.0, 18)
    };

    //when
    knuth_morris_pratt(pattern, text, supplier);

    //then
    ASSERT_EQ(coincidences, expected);
}