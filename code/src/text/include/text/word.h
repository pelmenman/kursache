#include <iostream>
#include <memory>

class Word {
public:
    unsigned long long hash() const;
    size_t size() const;
    Word(std::shared_ptr<std::string> text, size_t size, unsigned int hash_val, int pos = 0);

    char operator[](size_t index) const;

    int pos() const;

private:
    std::shared_ptr<std::string> _text;
    size_t _size;
    unsigned long long _hash;
    int _pos;

    std::string str() const; //TODO not many copyies

    friend std::ostream& operator<<(std::ostream &os, const Word& word);
};