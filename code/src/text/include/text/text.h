#include <vector>
#include <string>
#include <sstream>

class Text {
public:
    class Word {
    public:
        unsigned long long hash() const;
        size_t size() const;
        Word(size_t _size, int _pos, const Text& _from);

        char operator[](size_t index) const; 
    
    private:
        Word() = delete;
        unsigned long long _hash;
        size_t _size;
        int _pos;
        const Text& _from;

        void hashing();

        std::string str() const; //TODO not many copyies

        friend std::ostream& operator<<(std::ostream &os, const Word& word);
    };
public:

    Text(std::string text);

    size_t size() const;
    const Word& operator[](int i) const;
private:
    std::vector<Word> _words;
    std::string _text;
};
