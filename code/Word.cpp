#include <string>

class Word {
public:
    Word(std::string word) {
        this->word = word;
        hashIt();
    }

    std::string getWord() const {
        return this->word;
    }

     long long getHash() const {
        return this->hash;
     }
private:
    static const long long MODULE = 10e7 + 9;
    static const int ALPHABET_SIZE = 33;
    long long hash = 0;
    std::string word;

    void hashIt() {
        long long sub = 1;
        for(int i = 0; i < word.size(); i++) {
            hash = (hash + (word[i] - 'a' + 1)*sub % MODULE) % MODULE;
            sub *= ALPHABET_SIZE;
        }
    }
};