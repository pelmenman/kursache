#include <text/text.h>

using groups = std::map<unsigned int, std::list<Word>>;

class GroupedText {
public:
    GroupedText(std::shared_ptr<std::string> text,
                hash_func<std::string> mask,
                hash_func<std::string> to_hash);

    groups::iterator begin();
    groups::iterator end();
private:
    void preprocessing(hash_func<std::string> mask, hash_func<std::string> to_hash);

    std::shared_ptr<std::string> _text;
    groups _grouped;
};
