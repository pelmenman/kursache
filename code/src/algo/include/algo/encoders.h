#include <algo/constants.h>
#include <iostream>

// a = o
// c = k = s = z
// d = t
// e = i
// y = u
// v = w
// g = j
static const std::vector<int> weak_alph{
        0, 1, 2, 3, 4, 5, 6, 7, 4, 6, 2, 11, 12, 13, 0, 15, 16, 17, 2, 3, 20, 21, 21, 23, 20, 2
      //a, b, c, d, e, f, g, h, i, j, k,  l,  m,  n, o,  p,  q,  r, s, t,  u,  v,  w,  x,  y, z
};

unsigned int code(char c);

unsigned int weak_code(char c);
