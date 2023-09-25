#include <algo/algo.h>
#include <text/text.h>
#include <functional>

class BasePredictor { //_pattern in predictor
protected:
    std::string _pattern;
public:
    BasePredictor(std::string pattern);
    std::function<void(double, int)> _supplier;
    virtual void operator()(const Word& word) const = 0;
};

class KnutMorisPrattPredictor: public BasePredictor {
public:
    explicit KnutMorisPrattPredictor(std::string pattern);
    void operator()(const Word& word) const override;
};

class HashMaskPredictor: protected BasePredictor {
    unsigned int _mask;
public:
    explicit HashMaskPredictor(std::string pattern);
    void operator()(const Word& word) const override;
};

class BoyerMurPredictor: public BasePredictor {
    std::vector<int> _bad_chars;
public:
    explicit BoyerMurPredictor(std::string pattern);
    void operator()(const Word& word) const override;

};

class LevenshteinPredictor: public BasePredictor {
public:
    explicit LevenshteinPredictor(std::string pattern);
    void operator()(const Word& word) const override;
};

class WeakCodePredictor: public BasePredictor { //predicts only 18 signs word
public:
    explicit WeakCodePredictor(std::string pattern);
    void operator()(const Word& word) const override;
};

class HashEqualPredictor: public BasePredictor { //predicts only 18 signs word
    unsigned long long _pattern_hash;
public:
    explicit HashEqualPredictor(std::string pattern);
    void operator()(const Word& word) const override;
};

