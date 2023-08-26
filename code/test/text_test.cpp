#include <text/text.h>
#include <gtest/gtest.h>

auto text = Text(
    "Hello world from new project"
);

TEST(TextTests, TestNumOfWords) {
    //given
    const auto expectedNumWords = 5;
    
    //when
    const auto actualNumWords = text.size();

    //then
    ASSERT_EQ(actualNumWords, expectedNumWords);
}

TEST(TextTests, TestNumOfWordsWithBlankStr) {
    //given
    const auto blankText = Text("");
    const auto expectedNumWords = 0;
    
    //when
    const auto actualNumWords = blankText.size();

    //then
    ASSERT_EQ(actualNumWords, expectedNumWords);
} 

TEST(TextTests, TestGetWord) {
    //given

    //when
    const auto word = text[0];

    //then
    ASSERT_EQ(word.size(), 5);
}