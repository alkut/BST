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
public:
    std::vector<TNode<TKey>*> parents = {};
    const TKey& operator *() const;

    virtual BaseIteratorKeyOnly& operator ++();

protected:
    void goLeft();
    void goRight();
    /// if went left
    bool goUp();
};

template<class TKey, template <class> class TNode>
bool BaseIteratorKeyOnly<TKey, TNode>::goUp() {
    auto parent = parents.back();
    parents.pop_back();
    return parent->left == parents.back();
}

template<class TKey, template <class> class TNode>
void BaseIteratorKeyOnly<TKey, TNode>::goRight() {
    parents.push_back(parents.back()->right);
}

template<class TKey, template <class> class TNode>
void BaseIteratorKeyOnly<TKey, TNode>::goLeft() {
    parents.push_back(parents.back()->left);
}


template<class TKey, template <class> class TNode>
BaseIteratorKeyOnly<TKey, TNode>&
BaseIteratorKeyOnly<TKey, TNode>::operator++() {
    if (parents.empty()) {
        throw std::out_of_range("attempt to read nullptr in BaseIteratorKeyOnly::operator++");
    }
    auto cur = parents.back();
    if (cur->right != nullptr) {
        goRight();

        while (parents.back() != nullptr) {
            goLeft();
        }

        parents.pop_back();
        return *this;
    }
    while (true) {
        if (parents.size() == 1) {
            parents = {};
            return *this;
        }
        if (goUp()) {
            return *this;
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
