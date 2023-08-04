#include "../word/Word.h"
#include <vector>
#include <string>

class Text {
public:
    Text(const std::string& text);
    size_t size() const;
    const Word& operator[](int i) const;
private:
    std::vector<Word> words;
};
