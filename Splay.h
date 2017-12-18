//Splay.h
//Decalration of the splay tree
include "BST.h"

template <typename T>
class Splay : public BST<T>{
protected:
	BinNodePosi(T) splay(BinNodePosi(T) v);
	void attachAsLChild(BinNodePosi(T) p, BinNodePosi(T) lc){ p->lChild = lc; if(lc) lc->parent = p;}
	void attachAsRChild(BinNodePosi(T) p, BinNodePosi(T) rc){ p->rChild = rc; if(rc) rc->parent = p;}
public:
	BinNodePosi(T)& search(T const&);
	BinNodePosi(T)& insert(T const&);
	bool remve(T const&)
};