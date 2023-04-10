#include "Coincidence.h"
#include "Levenshtein.h"

Coincidence:: Coincidence() {}

int Coincidence::getCoincidence(Word word, Text text) {
	Levenshtein levenshtein;


	for (Word otherWord : text) {
		levenshtein.getMinDistance(word, word.getWord().size, otherWord.getWord().size);
	}
	
}
