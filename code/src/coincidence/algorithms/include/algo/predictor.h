#include <algo/algo.h>
#include <text/text.h>
#include <functional>

class BasePredictor { //pattern in predictor
public:
    std::function<void(double, int)> supplier;
    virtual void operator()(const Text::Word& pattern,const Text::Word& word) const;
};

class KnutMorisPrattPredictor: public BasePredictor {
public:
    void operator()(const Text::Word& pattern,const Text::Word& word) const override;
};

class HashMaskPredictor: public BasePredictor {
public:
    void operator()(const Text::Word& pattern,const Text::Word& word) const override;
};

class BoyerMurPredictor: public BasePredictor {
    std::string pattern;
    std::vector<int> bad_chars;
    std::vector<int> good_suffix;
public:
    void operator()(const Text::Word& pattern,const Text::Word& word) const override;

    BoyerMurPredictor(std::string pattern);
};

class LevenshteinPredictor: public BasePredictor {
public:
    void operator()(const Text::Word& pattern,const Text::Word& word) const override;
};

class WeakHashPredictor: public BasePredictor { //predicts only 18 signs word
public:
    void operator()(const Text::Word& pattern,const Text::Word& word) const override;
};

class MetricPredictor: public BasePredictor { // predicts on base metric
public:
    void operator()(const Text::Word& pattern,const Text::Word& word) const override;
};

