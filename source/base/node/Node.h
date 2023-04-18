#ifndef BST_NODE_H
#define BST_NODE_H

#include <stdexcept>

/**
 * @brief Storage for single vertex of tree
 * @tparam TKey mush be comparable with linear order
 */
template<class TKey>
class NodeKeyOnly;

/**
 * @brief Storage for single vertex of tree with extra info
 * @tparam TKey mush be comparable with linear order
 * @tparam TValue
 */
template<class TKey, class TValue>
class NodeKeyValue;




template<class TKey>
class NodeKeyOnly {
public:
    TKey key;
    NodeKeyOnly<TKey> *left = nullptr;
    NodeKeyOnly<TKey> *right = nullptr;
    NodeKeyOnly() = default;
    explicit NodeKeyOnly(const TKey key) : key(key) {}
    NodeKeyOnly(const TKey key, NodeKeyOnly<TKey> *left,
                NodeKeyOnly<TKey> *right) : key(key), left(left), right(right) {}
    NodeKeyOnly(const NodeKeyOnly&) = delete;
    static NodeKeyOnly *GetMin(NodeKeyOnly *root);
};

template<class TKey>
NodeKeyOnly<TKey> *NodeKeyOnly<TKey>::GetMin(NodeKeyOnly *root) {
    if (root == nullptr) {
        throw std::out_of_range("try to get min of empty sub tree");
    }
    while (true) {
        if (root->left == nullptr) {
            return root;
        }
        root = root->left;
    }
}


template<class TKey, class TValue>
class NodeKeyValue {
public:
    TKey key;
    TValue value;
    NodeKeyOnly<TKey> *left = nullptr;
    NodeKeyOnly<TKey> *right = nullptr;
    NodeKeyValue() = default;
    NodeKeyValue(const TKey key, const TValue value) : key(key), value(value) {}
    NodeKeyValue(const TKey key, const TValue value,
                 NodeKeyOnly<TKey> *left,
                NodeKeyOnly<TKey> *right) : key(key), value(value), left(left), right(right) {}
    NodeKeyValue(const NodeKeyValue&) = delete;
};

#endif //BST_NODE_H
