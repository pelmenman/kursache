#include <algo/hash.h>

unsigned int code(char c) {
    return islower(c) ?
           (c - 'a') + 1 :
           (c - 'A') + 1;
}

unsigned int weak_code(char c) {
    return (c - 'a' == weak_alph[c - 'a'] ?
            c - 'a' :
            weak_code(weak_alph[c - 'a'] + 'a'));
}