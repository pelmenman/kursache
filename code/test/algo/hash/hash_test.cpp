#include <coincidence/all.h>
#include<gtest/gtest.h>

TEST(HashTests, TestingPolyHash) {
    //given
    const auto str = "hello";

    //when
    const auto hash = poly_substr_hash(str, 5);

    //then
    ASSERT_EQ(hash, 14'222'002);
}

TEST(HashTests, TestingHashMask) {
    //given
    const auto str = "hello";

    //when
    const auto mask = mask_substr_hash(str, 5);

    //then
    ASSERT_EQ(mask, 18'576);
}

TEST(HashTests, TestingWeakHash) {
    //given
    const auto str = "hello";

    //when
    const auto hash = poly_substr_weak_hash(str, 5);

    //then
    ASSERT_EQ(hash,
              (weak_code('h') + 1) +
              (weak_code('e') + 1)*WEAK_ALPHABET_SIZE +
              (weak_code('l') + 1)*WEAK_ALPHABET_SIZE*WEAK_ALPHABET_SIZE +
              (weak_code('l') + 1)*WEAK_ALPHABET_SIZE*WEAK_ALPHABET_SIZE*WEAK_ALPHABET_SIZE +
              (weak_code('o') + 1)*WEAK_ALPHABET_SIZE*WEAK_ALPHABET_SIZE*WEAK_ALPHABET_SIZE*WEAK_ALPHABET_SIZE);

}