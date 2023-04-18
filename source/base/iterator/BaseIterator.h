#ifndef BST_BASE_ITERATOR_H
#define BST_BASE_ITERATOR_H

#include <stdexcept>
#include <vector>

/**
 *
 * @tparam TKey
 * @tparam TNode
 */
template<class TKey, template<class> class TNode>
class BaseIteratorKeyOnly;

/**
 *
 * @tparam TKey
 * @tparam TValue
 * @tparam TNode
 */
template<class TKey, class TValue, template<class> class TNode>
class BaseIteratorKeyValue;

template<class TKey, template<class> class TNode>
class BaseIteratorKeyOnly {
    std::vector<TNode<TKey>*> parents = {};
    const TKey& operator *() const;
    BaseIteratorKeyOnly& operator ++();
};



template<class TKey, template <class> class TNode>
BaseIteratorKeyOnly<TKey, TNode>&
BaseIteratorKeyOnly<TKey, TNode>::operator++() {
    auto cur = parents.back();
    if (cur->right != nullptr) {
        cur = cur->right;
        parents.push_back(cur);

        while (true) {
            cur = cur->left;
            if (cur != nullptr) {
                parents.push_back(cur);
            } else {
                return *this;
            }
        }
    }
    return *this;
}


template <class TKey, template <class> class TNode>
const TKey& BaseIteratorKeyOnly<TKey, TNode>::operator*() const {
    if (parents.empty()) {
        throw std::out_of_range("attempt to read nullptr in BaseIteratorKeyOnly");
    }
    return parents.back()->key;
}

#endif //BST_BASE_ITERATOR_H
