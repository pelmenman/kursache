#include <text/text.h>
#include <algo/hash.h>
#include <gtest/gtest.h>

const auto some_text = std::make_shared<std::string>("hello from");
const Text text(some_text, poly_substr_hash<std::string>);

TEST(WordTests, TestHash) {
    //given

    //when
    const auto hash_first = text[0].hash();
    const auto hash_second = text[1].hash();

    //then
    ASSERT_EQ(hash_first, 18'233'300);
    ASSERT_EQ(hash_second, 484'116);
}

TEST(WordTests, TestSize) {
    //given

    //when
    const auto size_first = text[0].size();
    const auto size_second = text[1].size();

    //then
    ASSERT_EQ(size_first, 5);
    ASSERT_EQ(size_second, 4);
}
