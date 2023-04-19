#ifndef BST_BASE_TREE_H
#define BST_BASE_TREE_H

#include <functional>

#include "base/iterator/BaseIterator.h"
#include "base/iterator/Reverse_Iterator.h"
#include "base/node/Node.h"

/**
 *
 * @tparam TKey
 * @tparam TNode
 * @tparam TComparator
 * @tparam TAllocator
 */
template<class TKey, template<class> class TNode, class TComparator = std::less<TKey>, class TAllocator = std::allocator<TKey>>
class BaseTreeKeyOnly;

/**
 *
 * @tparam TKey
 * @tparam TComparator
 * @tparam TAllocator
 */
template<class TKey, class TComparator = std::less<TKey>, class TAllocator = std::allocator<TKey>>
class BaseTree : BaseTreeKeyOnly<TKey, NodeKeyOnly, TComparator, TAllocator> {};



template<class TKey, template<class> class TNode, class TComparator, class TAllocator>
class BaseTreeKeyOnly {
public:
    BaseTreeKeyOnly();
    BaseTreeKeyOnly(const BaseTreeKeyOnly<TKey, TNode, TComparator, TAllocator>&);
    BaseTreeKeyOnly(BaseTreeKeyOnly<TKey, TNode, TComparator, TAllocator>&&);
    BaseTreeKeyOnly& operator = (const BaseTreeKeyOnly<TKey, TNode, TComparator, TAllocator>&);
    BaseTreeKeyOnly& operator = (BaseTreeKeyOnly<TKey, TNode, TComparator, TAllocator>&&);
    BaseIteratorKeyOnly<TKey, TNode> begin() const ;
    BaseIteratorKeyOnly<TKey, TNode> end() const ;
    ReverseIteratorKeyOnly<TKey, TNode> rbegin() const ;
    ReverseIteratorKeyOnly<TKey, TNode> rend() const ;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    void clear();
    BaseIteratorKeyOnly<TKey, TNode> insert(const TKey&);
    template< class... Args >
    BaseIteratorKeyOnly<TKey, TNode> emplace(Args&&... args);
    size_t erase(const TKey& key);
    BaseIteratorKeyOnly<TKey, TNode> erase(BaseIteratorKeyOnly<TKey, TNode> pos);
    void swap(BaseTreeKeyOnly<TKey, TNode, TComparator, TComparator>&);
    BaseIteratorKeyOnly<TKey, TNode> find(const TKey& key) const ;
    BaseIteratorKeyOnly<TKey, TNode> lower_bound(const TKey& key) const ;
    BaseIteratorKeyOnly<TKey, TNode> upper_bound(const TKey& key) const ;
private:
    TNode<TKey> *root = nullptr;
    size_t size_ = 0;
    BaseIteratorKeyOnly<TKey, TNode> begin_;
    const BaseIteratorKeyOnly<TKey, TNode> end_ = {};
    ReverseIteratorKeyOnly<TKey, TNode> rbegin_;
    const ReverseIteratorKeyOnly<TKey, TNode> rend_ = {};
};

template<class TKey, template<class> class TNode, class TComparator, class TAllocator>
BaseTreeKeyOnly<TKey, TNode, TComparator, TAllocator>::BaseTreeKeyOnly() = default;

#endif //BST_BASE_TREE_H
