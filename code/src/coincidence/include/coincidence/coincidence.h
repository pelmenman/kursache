#include <text/text.h>
#include <queue>
#include <map>

template<typename Predictor>
class Coincidence {
public:
	Coincidence(const Text& text, std::string pattern, Predictor predictor);

	void find();


private:
    Predictor predictor;
	Text text;
    std::string pattern;

	std::vector<std::tuple<double, int>> coincidences;

    Coincidence() = delete;
};

//TODO
//We go through the text comparing with a given word until we get 10 best coincidence
//Comparing with: hash/Levenshtein?
//Need to get percentages

//Draft
// while(coincidences.size() != 10) {
//	for(Word w : text) {
//		(getPercentage(levenshtein(word, w)) > 60)? coincidence.push(w) : continue;
//
// 	OR levenshetin is already gives percentages so
//		(levenshtein(word, w) > 60)? coincidence.push(w) : continue;
//
// if we have hashes instead of livenshtein then
//		(word.hash() == w.hash())? check(word, w) : continue;
//
//
//
//	}
//}

////Levenshtein
//int getPercentage(int count) {
//    //TODO
//}
