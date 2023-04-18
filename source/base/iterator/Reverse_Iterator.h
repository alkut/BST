#ifndef BST_REVERSE_ITERATOR_H
#define BST_REVERSE_ITERATOR_H

#include "base/iterator/BaseIterator.h"

template<class TKey, template<class> class TNode>
class ReverseIteratorKeyOnly: BaseIteratorKeyOnly<TKey, TNode> {
    ReverseIteratorKeyOnly<TKey, TNode>& operator ++() override;
};

template<class TKey, template<class> class TNode>
ReverseIteratorKeyOnly<TKey, TNode>&
ReverseIteratorKeyOnly<TKey, TNode>::operator++() {
    if (BaseIteratorKeyOnly<TKey, TNode>::parents.empty()) {
        throw std::out_of_range("attempt to read nullptr in BaseIteratorKeyOnly::operator++");
    }
    auto cur = BaseIteratorKeyOnly<TKey, TNode>::parents.back();
    if (cur->left != nullptr) {
        BaseIteratorKeyOnly<TKey, TNode>::goLeft();

        while (BaseIteratorKeyOnly<TKey, TNode>::parents.back() != nullptr) {
            BaseIteratorKeyOnly<TKey, TNode>::goRight();
        }

        BaseIteratorKeyOnly<TKey, TNode>::parents.pop_back();
        return *this;
    }
    while (true) {
        if (BaseIteratorKeyOnly<TKey, TNode>::parents.size() == 1) {
            BaseIteratorKeyOnly<TKey, TNode>::parents = {};
            return *this;
        }
        if (!BaseIteratorKeyOnly<TKey, TNode>::goUp()) {
            return *this;
        }
    }
    return *this;
}

#endif //BST_REVERSE_ITERATOR_H
