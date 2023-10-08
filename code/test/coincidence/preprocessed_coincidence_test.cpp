#include <coincidence/all.h>
#include <gtest/gtest.h>

TEST(PreprocessedCoincidence, KMPPredictor) {
    //given
    const auto str = std::make_shared<std::string>("zasdfasfhello my ggg bb fa frienfadzzzhello!!");
    GroupedText text(str, mask_substr_hash, poly_substr_hash);

    KnuthMorrisPrattPredictor predictor("fa");
    PreprocessedCoincidence<KnuthMorrisPrattPredictor> prep_coincidence(text, predictor);
    std::vector<std::tuple<double, int>> expected {
            std::make_tuple(1, 24),
            std::make_tuple(1, 32),
            std::make_tuple(1, 4)
    };

    //when
    prep_coincidence.find();

    //then
    ASSERT_EQ(expected, prep_coincidence.get());
}