#include <algo/algo.h>
#include <text/grouped_text.h>
#include <functional>

class BasePredictor {
public:
    BasePredictor(const std::string& pattern);
    const std::string& _pattern;
    std::function<void(double, int)> _supplier;
    virtual void operator()(const Word& word) const = 0;
};

class KnuthMorrisPrattPredictor: public BasePredictor {
public:
    explicit KnuthMorrisPrattPredictor(const std::string& pattern);
    void operator()(const Word& word) const override;
};

class HashMaskPredictor: public BasePredictor {
    unsigned int _mask;
public:
    explicit HashMaskPredictor(const std::string& pattern);
    void operator()(const Word& word) const override;
};

class BoyerMoorePredictor: public BasePredictor {
    std::vector<int> _bad_chars;
public:
    explicit BoyerMoorePredictor(const std::string& pattern);
    void operator()(const Word& word) const override;

};

class LevenshteinPredictor: public BasePredictor {
public:
    explicit LevenshteinPredictor(const std::string& pattern);
    void operator()(const Word& word) const override;
};

class WeakCodePredictor: public BasePredictor {
public:
    explicit WeakCodePredictor(const std::string& pattern);
    void operator()(const Word& word) const override;
};

class HashEqualPredictor: public BasePredictor {
    unsigned long long _pattern_hash;
public:
    explicit HashEqualPredictor(const std::string& pattern);
    void operator()(const Word& word) const override;
};

