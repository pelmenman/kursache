#include <string>
#include "../constants.h"

class Word {
public:
    long long hash() const;
    size_t size() const;

    Word(char* word, size_t size);

    Word(const std::string& str);

    char operator[](size_t index) const; 
    
private:
    Word() = delete;
    long long hash;
    char* word;
    size_t size;

    void hashing() const;

    friend std::ostream& operator<<(std::ostream &os, const Word& word);
};

std::ostream& operator<<(std::ostream &os, const Word& word);