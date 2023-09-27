#include <algo/predictor.h>
#include <queue>
#include <map>

template<typename Predictor>
class Coincidence {
public:
    Coincidence(const Text& text, Predictor predictor)
        : _text(text), _predictor(predictor)
    {
        _predictor._supplier = [&res = this->_coincidences](double per, int pos) {
            res.emplace_back(per, pos);
        };
    }

	void find() {
        int len = _text.size();

        for(int i = 0; i < len; i++) {
            _predictor(_text[i]);
        }
    }

    const std::vector<std::tuple<double, int>>& get() {
        return _coincidences;
    }
private:
    Predictor _predictor;
	const Text& _text;

	std::vector<std::tuple<double, int>> _coincidences;
};