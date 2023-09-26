#include <vector>
#include <string>
#include <text/word.h>
#include <text/utils.h>

class Text {
public:
    Text(std::shared_ptr<std::string> text,
         const hash_func& to_hash);

    std::vector<Word>::iterator begin();
    std::vector<Word>::iterator end();

    size_t size() const;
    const Word& operator[](int i) const;

//    Text(const Text& text) = default;
    //Text(Text&& text) = default;
private:
    std::vector<Word> _words;
    std::shared_ptr<std::string> _text;
};
