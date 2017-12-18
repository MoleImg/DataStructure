//BST.h
//Binary Search Tree
#include "BinTree.h"

template <typename T> class BST : public BinTree<T>{
	protected:
		BinNodePosi(T) _hot;
		BinNodePosi(T) connect34(BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
			BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
		BinNodePosi(T) rotateAt(BinNodePosi(T));
		static BinNodePosi(T) removeAt(BinNodePosi(T) &x, BinNodePosi(T) &hot);

	public:
		virtual BinNodePosi(T) & search(T const &);
		virtual BinNodePosi(T) & insert(T const &);
		virtual bool remove(T const &);
}