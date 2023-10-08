#include <iostream>
#include <coincidence/all.h>
#include <string>
#include <fstream>
#include <iterator>
#include <chrono>



template<typename Predictor>
long long timed(PreprocessedCoincidence<Predictor>& coincidence) {
    auto begin = std::chrono::steady_clock::now();
    coincidence.find();
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    return elapsed_ms.count();
}

template<typename Predictor>
long long byTextSize(std::shared_ptr<std::string> str, std::string pattern) {
    GroupedText text(str, mask_substr_hash, poly_substr_hash);
    Predictor predictor(pattern);

    PreprocessedCoincidence<Predictor> coincidence(text, predictor);

    auto res = timed(coincidence);

    auto finded = coincidence.get();

    for(auto& val: finded) {
        std::cout << "| " << std::get<0>(val) << ' ' << std::get<1>(val) << " ";
    }
    std::cout << "| res:";

    return res;
}

template<>
long long byTextSize<HashMaskPredictor>(std::shared_ptr<std::string> str, std::string pattern) {
    GroupedText text(str, mask_substr_hash, mask_substr_hash);
    HashMaskPredictor predictor(pattern);

    PreprocessedCoincidence<HashMaskPredictor> coincidence(text, predictor);

    auto res = timed(coincidence);

    auto finded = coincidence.get();

    for(auto& val: finded) {
        std::cout << "| " << std::get<0>(val) << ' ' << std::get<1>(val) << " ";
    }
    std::cout << "| res: ";

    return res;
}


int main() {
    std::ifstream ifs("../../resources/text200.txt");
    std::string str(std::istreambuf_iterator<char>{ifs}, {});

    const auto txt = std::make_shared<std::string>(str);
    std::cout << exp(15) << '\n';

    std::cout << "Text with 200 words: finds \"patients\" " << '\n';

    std::cout << "KnuttMorisPrattPredictor: " << byTextSize<KnuthMorrisPrattPredictor>(txt, "patients") << '\n';
    std::cout << "BoyerMurPredictor: " << byTextSize<BoyerMoorePredictor>(txt, "patients") << '\n';
    std::cout << "HashMaskPredictor: " << byTextSize<HashMaskPredictor>(txt, "patients") << '\n';
    std::cout << "LevenshteinPredictor: " << byTextSize<LevenshteinPredictor>(txt, "patients") << '\n';
    std::cout << "WeakCodePredictor: " << byTextSize<WeakCodePredictor>(txt, "patients") << '\n';
    std::cout << "HashEqualPredictor: " << byTextSize<HashEqualPredictor>(txt, "patients") << '\n';


}
