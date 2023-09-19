static const unsigned long long MOD = 10e9 + 7;
static const unsigned int ALPHABET_SIZE = 31;

std::vector<unsigned long long> vals(1, 1);

static unsigned long long exp(int pow);

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

static std::vector<unsigned int> pows2(32);

// a = o
// c = k = s = z
// d = t
// e = i
// y = u
// v = w
static const std::vector<int> weak_alph{
    0, 1, 2, 3, 4, 5, 6, 7, 4, 8, 2, 9, 10, 11, 0, 12, 13, 14, 2, 3, 15, 16, 16, 17, 15, 2
  //a, b, c, d, e, f, g, h, i, j, k, l,  m,  n, o,  p,  q,  r, s, t,  u,  v,  w,  x,  y, z
};

static const double EQUAL_PERCANTAGE = 0.8;