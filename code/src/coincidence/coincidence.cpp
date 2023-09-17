#include <coincidence/coincidence.h>

template<typename Predictor>
Coincidence<Predictor>::Coincidence(
        const Text& text,
        std::string pattern,
        Predictor predictor
) : text(text),
    pattern(pattern),
    predictor(predictor)
{

    predictor.supplier = [&res = this->coincidences](double per, int pos) {
        res.emplace_back(per, pos);
    };
}

template<typename Predictor>
void Coincidence<Predictor>::find() {
    int len = text.size();

    for(int i = 0; i < len; i++) {
        predictor(text[i], pattern);
    }
}


