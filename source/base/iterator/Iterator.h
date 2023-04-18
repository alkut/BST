#ifndef BST_ITERATOR_H
#define BST_ITERATOR_H

#include "base/iterator/BaseIterator.h"

template<class TKey, template<class> class TNode>
class IteratorKeyOnly: BaseIteratorKeyOnly<TKey, TNode> {
};

#endif //BST_ITERATOR_H
