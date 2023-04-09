#pragma once

class Levenshtein {
public:
    static Levenshtein* getInstance();
private:
    Levenshtein();
    static inline Levenshtein* realization = nullptr;
};