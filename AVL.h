//AVL.h
//Declaration of the AVL tree
#include "BST.h"

#define Balanced(x) (stature((x).lChild) == stature((x).rChild))
#define BalFac(x) (stature((x).lChild) - stature((x).rChild))
#define AvlBalanced(x) ((-2<BalFac(x)) && (BalFac(x)<2))

template <typename T> class AVL:public BST<T>{
public:
	BinNodePosi(T) insert(T const&);
	bool remove(T const&);	
};
