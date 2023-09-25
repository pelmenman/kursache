#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <text/word.h>

template<typename Pattern>
using hash_func = std::function<unsigned long long(const Pattern&, int, int)>;

class Text {
public:
    Text(std::shared_ptr<std::string> text, hash_func<std::string> to_hash);

    std::vector<Word>::iterator begin();
    std::vector<Word>::iterator end();

    size_t size() const;
    const Word& operator[](int i) const;

    //Text(Text&& text) = default;
private:
    std::vector<Word> _words;
    std::shared_ptr<std::string> _text;
};
