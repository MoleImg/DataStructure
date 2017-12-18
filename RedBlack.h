//RedBlack.h
//Declaration of redblack tree
#include "BST.h"

template <typename T> class RedBlack : public BST<T> {
protected:
	void solveDoubleRed(BinNodePosi(T));
	void solveDoubleBlack(BinNodePosi(T));
	int updateHeight(BinNodePosi(T));

public:
	BinNodePosi(T) insert(T const&);
	bool remove(T const&);
};