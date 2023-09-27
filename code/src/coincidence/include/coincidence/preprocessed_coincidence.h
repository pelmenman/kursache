#include <coincidence/coincidence.h>
#include <vector>

template<typename Predictor>
class PreprocessedCoincidence {
public:
    PreprocessedCoincidence(GroupedText &text, Predictor predictor)
            : _text(text), _predictor(predictor)
    {
        _predictor._supplier = [&res = this->_coincidence](double per, int pos) {
            res.emplace_back(per, pos);
        };
    }

    void find() {
        unsigned int mask = mask_substr_hash(_predictor._pattern, _predictor._pattern.size());

        auto it = _text.begin();
        while(it != _text.end()) {
            if((it->first & mask) >= mask) {
                auto list_it = it->second.begin();
                while(list_it != it->second.end()) {
                    _predictor(*list_it);
                    list_it++;
                }
            }
            it++;
        }
    }

    std::vector<std::tuple<double, int>> get() {
        return _coincidence;
    }

private:
    Predictor _predictor;
    GroupedText& _text;

    std::vector<std::tuple<double, int>> _coincidence;
};
