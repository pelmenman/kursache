#include <text/grouped_text.h>

GroupedText::GroupedText(std::shared_ptr<std::string> text,
                         const hash_func& mask,
                         const hash_func& to_hash)
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

size_t GroupedText::size() const {
    return _grouped.size();
}

void GroupedText::preprocessing(const hash_func& mask, const hash_func& to_hash) {
    int size;
    int shift;
    unsigned int hashed_mask;

    for(int i = 0; i < _text->size(); ++i) {
        if (is_symb(_text->operator[](i))) {
            size = 0;
            shift = i;
            for( ; is_symb(_text->operator[](i)); ++i) ++size;

            hashed_mask = mask(*_text, size, shift);
            if(_grouped.find(hashed_mask) == _grouped.end()) _grouped[hashed_mask] = std::list<Word>();

            _grouped[hashed_mask].emplace_back(
                    _text, size,to_hash(*_text, size, shift),shift);
        }
    }
}