#include <coincidence/preprocessed_coincidence.h>
#include <gtest/gtest.h>

TEST(CoincidenceTest, TestCoincidenceWithKnuttPredictor) {
    //given
    const auto str = std::make_shared<std::string>("hello my friendzzz!!");
    const Text text(str, poly_substr_hash);
    //std::cout << text.size();
    KnutMorisPrattPredictor predictor("hello");
    std::vector<std::tuple<double, int>> coincidence;
    //Coincidence<KnutMorisPrattPredictor> coincidence(text, predictor);



//    //when
//    coincidence.find();
//
//    //then
//    auto it = coincidence.get().begin();
//    while(it++ != coincidence.get().end()) {
//        std::cout << std::get<0>(*it) << ' ' << std::get<1>(*it) << '\n';
//    }
}