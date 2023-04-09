#include <iostream>
#include <string>
using namespace std;

class Word {
public:
    Word(string word) {
        hashIt(word);
    }

    string getWord() const {
        return word;
    }

    long long getHash() const {
        return hash;
    }
private:
    long long hash = 0;
    string word;

    void hashIt(string word) {
        for(int i = 0; i < word.size(); i++) {
            hash = (hash +
        }
    }
};