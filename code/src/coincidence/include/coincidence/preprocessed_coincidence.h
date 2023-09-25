#include <text/grouped_text.h>

template<typename Predictor>
class PreprocessedCoincidence {
public:
    PreprocessedCoincidence(GroupedText& text, Predictor predictor);

    void find();
private:
    Predictor _predictor;
    GroupedText& _text;

    std::vector<std::tuple<double, int>> _coincidence;
};
