//BST.cpp
//Implementation of Binary Search Tree
#include "BST.h"

template <typename T>
BinNodePosi(T)& BST<T>::search(T const &e){
	return searchIn(_root, e, _hot = NULL);
}

template <typename T>
static BinNodePosi(T)& searchIn(BinNodePosi(T) &v, T const &e, BinNodePosi(T) hot){
	if(!v || e == v->data) return v;
	hot = v;
	return searchIn((e<v->data)?v->lChild:v->rChild, e, hot);
}

template <typename T>
BinNodePosi(T)& insert(T const &e){
	BinNodePosi(T) x = search(e); if(x) return x;
	x = new BinNode<T>(e, _hot);
	_size++;
	updateHeightAbove(x);
	return x;
}

template <typename T>
bool BST<T>::remove(T const &e){
	BinNodePosi(T) &x = search(e);
	if(!x) return false;
	removeAt(x, _hot);
	_size--;
	updateHeightAbove(_hot);
	return true;
}

template <typename T>
BinNodePosi(T) removeAt(BinNodePosi(T) &x, BinNodePosi(T) &hot){
	BinNodePosi(T) w = x;
	BinNodePosi(T) succ = NULL;
	if(!HasLChild(*x)) succ = x = x->rChild;
	if(!HasRChild(*x)) succ = x = x->lChild;
	else{
		w = w->succ();
		swap(w->data, x->data);
		BinNodePosi(T) u = w->parent;
		((u==x)?u->rChild:u->lChild) = succ = w->rChild;
	}
	hot = w->parent;
	if(succ) succ->parent = hot;
	release(w->data); release(w);
	return succ;
}