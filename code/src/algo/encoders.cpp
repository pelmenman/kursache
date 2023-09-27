#include <algo/encoders.h>

unsigned int code(char c) {
    return islower(c) ?
           (c - 'a') + 1 :
           (c - 'A') + 1;
}

//unsigned int weak_code(char c) {
//    return (c - 'a' == weak_alph[c - 'a'] ?
//            c - 'a' :
//            weak_code((char)(weak_alph[c - 'a'] + (int)'a')));
//}
unsigned int weak_code(char c) {
    return weak_alph[c - 'a'] + 1;
}
