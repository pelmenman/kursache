#include <vector>

static const unsigned long long MOD = 1e9 + 7;
static const unsigned int ALPHABET_SIZE = 31;
static const unsigned int WEAK_ALPHABET_SIZE = 17;
static const double EQUAL_PERCENTAGE = 0.5;

static std::vector<unsigned long long> vals(1, 1);

static unsigned long long exp(int pow) {
    if(pow < vals.size()) return vals[pow];

    for(size_t i = vals.size(); i <= pow; i++) {
        vals.push_back((vals[i - 1] * ALPHABET_SIZE) % MOD);
    }

    return vals[pow];
}

static std::vector<unsigned long long> vals_weak(1, 1);

static unsigned long long exp_weak(int pow) {
    if(pow < vals_weak.size()) return vals_weak[pow];

    for(size_t i = vals_weak.size(); i <= pow; i++) {
        vals_weak.push_back((vals_weak[i - 1] * WEAK_ALPHABET_SIZE) % MOD);
    }

    return vals_weak[pow];
}

template <unsigned int N>
struct pows_two {
    enum
    {
        value = pows_two<N-1>::value << 1
    };
    static void add_values(std::vector<unsigned int>& v)
    {
        pows_two<N-1>::add_values(v);
        v[N - 1] = value;
    }
};

template <>
struct pows_two<1> {
    enum
    {
        value = 1
    };
    static void add_values(std::vector<unsigned int>& v)
    {
        v[0] = value;
    }
};

static std::vector<unsigned int> pows_2(32);

static unsigned int get_pow_2(unsigned int pow) {
    if(pows_2[pow] == 0) pows_two<32>::add_values(pows_2);
    return pows_2[pow];
}


