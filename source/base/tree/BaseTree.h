#ifndef BST_BASE_TREE_H
#define BST_BASE_TREE_H

#include <functional>

#include "base/iterator/BaseIterator.h"
#include "base/iterator/Reverse_Iterator.h"
#include "base/node/Node.h"

/**
 *
 * @tparam TKey
 * @tparam TComparator
 * @tparam TAllocator
 */
template<class TKey, class TComparator = std::less<TKey>, class TAllocator = std::allocator<TKey>>
class BaseTree {
public:
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> begin() const ;
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> end() const ;
    ReverseIteratorKeyOnly<TKey, NodeKeyOnly> rbegin() const ;
    ReverseIteratorKeyOnly<TKey, NodeKeyOnly> rend() const ;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    void clear();
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> insert(const TKey&);
    template< class... Args >
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> emplace(Args&&... args);
    size_t erase(const TKey& key);
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> erase(BaseIteratorKeyOnly<TKey, NodeKeyOnly> pos);
    void swap(BaseTree<TKey, TComparator, TComparator>&);
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> find(const TKey& key) const ;
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> lower_bound(const TKey& key) const ;
    BaseIteratorKeyOnly<TKey, NodeKeyOnly> upper_bound(const TKey& key) const ;
};

template<class TKey, class TComparator, class TAllocator>
BaseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::upper_bound(const TKey &key) const {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
BaseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::lower_bound(const TKey &key) const {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
BaseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::find(const TKey &key) const {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}


template<class TKey, class TComparator, class TAllocator>
void BaseTree<TKey, TComparator, TAllocator>::swap(BaseTree<TKey, TComparator, TComparator> &) {

}

template<class TKey, class TComparator, class TAllocator>
BaseIteratorKeyOnly<TKey, NodeKeyOnly>
BaseTree<TKey, TComparator, TAllocator>::erase(BaseIteratorKeyOnly<TKey, NodeKeyOnly> pos) {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
size_t BaseTree<TKey, TComparator, TAllocator>::erase(const TKey &key) {
    return 0;
}

template<class TKey, class TComparator, class TAllocator>
template<class... Args>
BaseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::emplace(Args &&... args) {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
BaseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::insert(const TKey &) {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
void BaseTree<TKey, TComparator, TAllocator>::clear() {

}

template<class TKey, class TComparator, class TAllocator>
size_t BaseTree<TKey, TComparator, TAllocator>::size() const {
    return 0;
}

template<class TKey, class TComparator, class TAllocator>
bool BaseTree<TKey, TComparator, TAllocator>::empty() const {
    return false;
}

template<class TKey, class TComparator, class TAllocator>
ReverseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::rend() const {
    return ReverseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
ReverseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::rbegin() const {
    return ReverseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
BaseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::end() const {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}

template<class TKey, class TComparator, class TAllocator>
BaseIteratorKeyOnly<TKey, NodeKeyOnly> BaseTree<TKey, TComparator, TAllocator>::begin() const {
    return BaseIteratorKeyOnly<TKey, NodeKeyOnly>();
}


#endif //BST_BASE_TREE_H
