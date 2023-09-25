#include <text/text.h>
#include <algo/hash.h>
#include <gtest/gtest.h>

const auto default_text = std::make_shared<std::string>("Hello world from new project");
const auto blank_text = std::make_shared<std::string>("");
const Text text(default_text, poly_substr_hash<std::string>);

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
    const auto blankText = std::move(Text(blank_text, poly_substr_hash<std::string>));
    const auto expectedNumWords = 0;
    
    //when
    const auto actualNumWords = blankText.size();

    //then
    ASSERT_EQ(actualNumWords, expectedNumWords);
} 

TEST(TextTests, TestGetWord) {
    //given

    //when
    const auto& word = text[0];

    //then
    ASSERT_EQ(word.size(), 5);
}