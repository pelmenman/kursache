#include "word/Word.h"
#include "text/Text.h"
#include <queue>
#include <map>

class Coincidence {
public: 
	Coincidence() = default;

	Coincidence(const Text& text, const Word& word): text(text), word(word) {};

	void getCoincidence() {	
		//TODO
		//We go through the text comparing with a given word until we get 10 best coincidence
		//Comparing with: hash/Levenshtein?
		//Need to get percentages 

		//Draft
		// while(coincidences.size() != 10) {
		//	for(Word w : text) {
		//		(getPercentage(levenshtein(word, w)) > 60)? coincidence.insert(w) : continue;
		//	}
		//}
	}

private:
	Text text; 
	Word word;
	std::priority_queue<Word, int> coincidences;

	//Levenshtein
	int getPercentage(int count) { 
		//TODO 
	}

};
