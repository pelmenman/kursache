#include <coincidence/all.h>
#include <gtest/gtest.h>

TEST(WordTests, TestHash) {
    //given
    const auto some_text = std::make_shared<std::string>("hello from");
    const Text text(some_text, poly_substr_hash);

    //when
    const auto hash_first = text[0].hash();
    const auto hash_second = text[1].hash();

    //then
    ASSERT_EQ(hash_first, 14'222'002);
    ASSERT_EQ(hash_second,
              ('f' - 'a' + 1) +
              ('r' - 'a' + 1)*ALPHABET_SIZE +
              ('o' - 'a' + 1)*ALPHABET_SIZE*ALPHABET_SIZE +
              ('m' - 'a' + 1)*ALPHABET_SIZE*ALPHABET_SIZE*ALPHABET_SIZE);
}

TEST(WordTests, TestSize) {
    //given
    const auto some_text = std::make_shared<std::string>("hello from");
    const Text text(some_text, poly_substr_hash);

    //when
    const auto size_first = text[0].size();
    const auto size_second = text[1].size();

    //then
    ASSERT_EQ(size_first, 5);
    ASSERT_EQ(size_second, 4);
}
