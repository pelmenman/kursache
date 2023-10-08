#include <coincidence/all.h>
#include <gtest/gtest.h>

TEST(TextTests, TestNumOfWords) {
    //given
    const auto expectedNumWords = 5;
    const auto default_text = std::make_shared<std::string>("Hello world from new project");
    const Text text(default_text, poly_substr_hash);

    //when
    const auto actualNumWords = text.size();

    //then
    ASSERT_EQ(actualNumWords, expectedNumWords);
}

TEST(TextTests, TestNumOfWordsWithBlankStr) {
    //given
    const auto blank_text = std::make_shared<std::string>("");
    const Text text(blank_text, poly_substr_hash);
    const auto expectedNumWords = 0;

    //when
    const auto actualNumWords = text.size();

    //then
    ASSERT_EQ(actualNumWords, expectedNumWords);
}

TEST(TextTests, TestGetWord) {
    //given
    const auto default_text = std::make_shared<std::string>("Hello world from new project");
    const Text text(default_text, poly_substr_hash);

    //when
    const auto& word = text[0];

    //then
    ASSERT_EQ(word.size(), 5);
}