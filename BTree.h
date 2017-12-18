//BTree.h
//Declaration of B-tree
#include "BTNode.h"
#define BTNodePosi(T) BTNode<T>*
template <typename T> class BTree{
protected:
	int _size; int _order; BTNodePosi(t) _root;
	BTNodePosi(T) _hot;
	void solveOverflow(BTNodePosi(T));
	void solveUnderflow(BTNodePosi(T));

public:
	BTNodePosi(T) search(T const&);
	bool insert(T const&);
	bool remove(T&);
};