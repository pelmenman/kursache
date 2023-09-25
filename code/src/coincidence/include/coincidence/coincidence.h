#include <text/text.h>
#include <queue>
#include <map>

template<typename Predictor>
class Coincidence {
public:
	Coincidence(const Text& text, Predictor predictor);

	void find();
private:
    Predictor predictor;
	const Text& text;

	std::vector<std::tuple<double, int>> coincidences;
};



