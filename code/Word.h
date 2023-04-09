#include <string>

class Word {
public:
    Word(std::string& word);

    std::string getWord() const;
    long long getHash() const;
private:
    static const long long MODULE = 10e7 + 9;
    static const int ALPHABET_SIZE = 33;
    long long hash = 0;
    std::string word;

    void hashIt();
};
