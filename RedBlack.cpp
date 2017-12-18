//RedBlack.cpp
//Implementation of redblack tree
#include "RedBlack"

template <typename T>
int RedBlack<T>::updateHeight(BinNodePosi(T) x){
	x->height = max(stature(x->lc), stature(x->rc));
	if(IsBlack(x)) x->height++;
	return x->height;
}

template <typename T>
void RedBlack<T>::solveDoubleRed(BinNodePosi(T) x){}

template <typename T>
BinNodePosi(T) RedBlack<T>::insert(T const& e){
	BinNodePosi(T) &x = search(e); if(x) return x;
	x = new BinNode<T>(e, _hot, NULL, NULL, -1);
	_size++;
	solveDoubleRed(x);
	return x?x:_hot->parent;
}

template <typename T>
bool RedBlack<T>::remove(T const &e){}
