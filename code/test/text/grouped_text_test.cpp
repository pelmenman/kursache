#include <coincidence/all.h>
#include <gtest/gtest.h>

TEST(GroupedTextTests, GroupedTextSize) {
    //given
    const auto str = std::make_shared<std::string>("hello oleh hell rare");
    const GroupedText text(str, mask_substr_hash, poly_substr_hash);
    auto expected_size = 3;

    //when
    auto actual_size = text.size();

    //then
    ASSERT_EQ(expected_size, actual_size);
}

TEST(GroupedTextTests, GroupSize) {
    //given
    //pows_two<32>::add_values(pows2);
    const auto str = std::make_shared<std::string>("hello oleh hell rare");
    GroupedText text(str, mask_substr_hash, poly_substr_hash);
    auto expected_group_size = 2;

    //when
    auto it = text.begin();
    while(it->first != 18'576 && it++ != text.end()) {}

    //then
    ASSERT_EQ(expected_group_size, it->second.size());
}