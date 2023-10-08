#include <coincidence/all.h>
#include <gtest/gtest.h>

TEST(CoincidenceTest, TestCoincidenceWithKnuttPredictor) {
    //given
    const auto str = std::make_shared<std::string>("zasdfasfhello my friendzzzhello!!");
    const Text text(str, poly_substr_hash);

    KnutMorisPrattPredictor predictor("hello");
    Coincidence<KnutMorisPrattPredictor> coincidence(text, predictor);
    std::vector<std::tuple<double, int>> expected {
        std::make_tuple(1, 8),
        std::make_tuple(1, 26)
    };

    //when
    coincidence.find();

    //then
    ASSERT_EQ(expected, coincidence.get());
}

TEST(CoincidenceTest, TestCoincidenceWithHashMaskPredictor) {
    //given
    const auto str = std::make_shared<std::string>("abcde abced adfcasf asdfhaksj");
    const Text text(str, mask_substr_hash);

    HashMaskPredictor predictor("abcde");
    Coincidence<HashMaskPredictor> coincidence(text, predictor);
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(1, 0),
            std::make_tuple(0.6, 6)
    };

    //when
    coincidence.find();

    //then
    ASSERT_EQ(expected, coincidence.get());
}

TEST(CoincidenceTest, TestCoincidenceWithBMPredictor) {
    //given
    const auto str = std::make_shared<std::string>("zasdfasfhello my friendzzzhello!!");
    const Text text(str, poly_substr_hash);

    BoyerMurPredictor predictor("hello");
    Coincidence<BoyerMurPredictor> coincidence(text, predictor);
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(1, 8),
            std::make_tuple(1, 26)
    };

    //when
    coincidence.find();

    //then
    ASSERT_EQ(expected, coincidence.get());
}

TEST(CoincidenceTest, TestCoincidenceWithLevenshteinPredictor) {
    //given
    const auto str = std::make_shared<std::string>("sfhello my hello friendzzzhello!!");
    const Text text(str, poly_substr_hash);

    LevenshteinPredictor predictor("hello");
    Coincidence<LevenshteinPredictor> coincidence(text, predictor);
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(0.714286, 0),
            std::make_tuple(1, 11)
    };

    //when
    coincidence.find();

    //then
    ASSERT_EQ(expected, coincidence.get());
}

TEST(CoincidenceTest, TestCoincidenceWithWeakCodePredictor) {
    //given
    const auto str = std::make_shared<std::string>("hilla my hello friendzzzhello hella!!");
    const Text text(str, poly_substr_hash);

    WeakCodePredictor predictor("hello");
    Coincidence<WeakCodePredictor> coincidence(text, predictor);
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(1, 0),
            std::make_tuple(1, 9),
            std::make_tuple(1, 24),
            std::make_tuple(1, 30)
    };

    //when
    coincidence.find();

    //then
    ASSERT_EQ(expected, coincidence.get());
}

TEST(CoincidenceTest, TestCoincidenceWithHashEqualPredictor) {
    //given
    const auto str = std::make_shared<std::string>("hello my hello friendzzzhello hella!!");
    const Text text(str, poly_substr_hash);

    HashEqualPredictor predictor("hello");
    Coincidence<HashEqualPredictor> coincidence(text, predictor);
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(1, 0),
            std::make_tuple(1, 9)
    };

    //when
    coincidence.find();

    //then
    ASSERT_EQ(expected, coincidence.get());
}