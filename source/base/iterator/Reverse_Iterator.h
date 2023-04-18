#ifndef BST_REVERSE_ITERATOR_H
#define BST_REVERSE_ITERATOR_H

#include "base/iterator/BaseIterator.h"

template<class TKey, template<class> class TNode>
class ReverseIteratorKeyOnly: BaseIteratorKeyOnly<TKey, TNode> {

};

#endif //BST_REVERSE_ITERATOR_H
