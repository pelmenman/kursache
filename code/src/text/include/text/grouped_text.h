#include <list>
#include <map>
#include <text/text.h>

using groups = std::map<unsigned int, std::list<Word>>;

class GroupedText {
public:
    GroupedText(std::shared_ptr<std::string> text,
                const hash_func& mask,
                const hash_func& to_hash);

    groups::iterator begin();
    groups::iterator end();

    size_t size() const;
private:
    void preprocessing(const hash_func& mask, const hash_func& to_hash);

    std::shared_ptr<std::string> _text;
    groups _grouped;
};
