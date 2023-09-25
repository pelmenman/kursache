#include <text/grouped_text.h>
#include <text/utils.h>

GroupedText::GroupedText(std::shared_ptr<std::string> text,
                         hash_func<std::string> mask,
                         hash_func<std::string> to_hash)
    : _text(text)
{
    preprocessing(mask, to_hash);
}


groups::iterator GroupedText::begin() {
    return _grouped.begin();
}

groups::iterator GroupedText::end() {
    return _grouped.end();
}

void GroupedText::preprocessing(hash_func<std::string> mask, hash_func<std::string> to_hash) {
    for(int i = 0; i < _text->size(); ++i) {
        if (is_symb(_text->operator[](i))) {
            int size = 0;
            int shift = i;
            for( ; ; ++i) {
                if(!is_symb(_text->operator[](i))) break;
                ++size;
            }

            unsigned int hashed_mask = mask(*_text, shift, size);
            if(_grouped.find(hashed_mask) == _grouped.end()) _grouped[hashed_mask] = std::list<Word>();

            _grouped.find(hashed_mask)->second.emplace_back(
                    _text, size,to_hash(*_text, shift, size),shift);
        }
    }
}