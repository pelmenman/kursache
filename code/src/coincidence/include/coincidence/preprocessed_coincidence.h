#include <coincidence/coincidence.h>
#include <vector>

template<typename Predictor>
class PreprocessedCoincidence {
public:
    PreprocessedCoincidence(GroupedText &text, Predictor predictor)
            : _text(text), _predictor(predictor)
    {
        predictor._supplier = [&res = this->coincidences](double per, int pos) {
            res.emplace_back(per, pos);
        };
    }

    void find() {
        unsigned int mask = _predictor._pattern;

        auto it = _text.begin();
        while(it++ != _text.end()) {
            if((it->first & mask) >= mask) {
                auto list_it = it->second.begin();
                while(list_it++ != it->second.end()) {
                    _predictor(*list_it);
                }
            }
        }
    }

private:
    Predictor _predictor;
    GroupedText& _text;

    std::vector<std::tuple<double, int>> _coincidence;
};
