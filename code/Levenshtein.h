#pragma once

class Levenshtein {
public:
    static Levenshtein getInstance();
private:
    Levenshtein();
    static Levenshtein* realization;
};