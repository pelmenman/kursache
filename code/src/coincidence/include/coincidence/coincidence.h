#include <algo/predictor.h>
#include <queue>
#include <map>

template<typename Predictor>
class Coincidence {
public:
    Coincidence(const Text& text, Predictor predictor)
        : text(text), predictor(predictor)
    {
        predictor._supplier = [&res = this->coincidences](double per, int pos) {
            res.emplace_back(per, pos);
        };
    }

	void find() {
        int len = text.size();

        for(int i = 0; i < len; i++) {
            predictor(text[i]);
        }
    }

    const std::vector<std::tuple<double, int>>& get() {
        return coincidences;
    }
private:
    Predictor predictor;
	const Text& text;

	std::vector<std::tuple<double, int>> coincidences;
};