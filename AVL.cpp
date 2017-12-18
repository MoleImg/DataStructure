//AVL.cpp
//Implementation of AVL tree
#include "AVL.h"

template <typename T>
BinNodePosi(T) AVL<T>::insert(T const& e){
	BinNodePosi(T) &x = search(e); if (x) return x;
	x = new BinNode<T>(e, _hot);
	_size++;
	BinNodePosi(T) xx = x;
	// Keep AVL balanced
	for(BinNodePosi(T) g = g->parent; g; g = g->parent){
		if(!AvlBalanced(*g)){	//if find the lowest unbalanced node
			FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g))); //rotation
			break;
		} else{
			updateHeightAbove(g);
		}
	}
	return xx;
}

template <typename T>
bool AVL<T>::remove(T const& e){
	BinNodePosi(T) &x = search(e); if (!x) return false;
	removeAt(x, _hot); _size--;
	//search for all the unbalanced parent nodes
	for(BinNodePosi(T) g = _hot; g; g->parent){	//once find the unbalanced node
		if(!AvlBalanced(*g)){
			g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
			updateHeight(g);
		}
	}
	return true;
}

template <typename T>
BinNodePosi(T) BST<T>::connect34(BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
	BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3){
	a->lChild = T0; if(T0) T0->parent = a;
	a->rChild = T1; if(T1) T1->parent = a;
	updateHeight(a);
	c->lChild = T2; if(T2) T2->parent = c;
	c->rChild = T3; if(T3) T3->parent = c;
	updateHeight(c);
	b->lChild = a; a->parent = b;
	b->rChild = c; c->parent = b;
	updateHeight(b);
	return b;

}