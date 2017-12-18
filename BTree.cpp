//BTree.cpp
//Implementation of B-Tree
#include "BTree.h"

template <typename T>
BTNodePosi(T) BTree<T>::search(T const &e){
	BTNodePosi(T) v = _root; _hot = NULL;
	while(v){
		Rank r = v->key.search(e);
		if((0<=r) && (e == v->key[r])) return v;	// succeed, return current node
		_hot = v; v = v->child[r+1];
	}
	return NULL; // fail
}

template <typename T>
bool BTree<T>::insert(T const& e){
	BTNodePosi(T) v = search(e); if(v) return false;
	Rank r = _hot->key.search(e);
	_hot->key.insert(r+1, e);
	_hot->child.insert(r+2, NULL);
	_size++;
	solveOverflow(_hot);
	return true;
}

template <typename T>
bool BTree<T>::remove(T &e){
	BinNodePosi(T) v = search(e); if(!v) return false;
	Rank r = v->key.search(e);
	if(v->child[0]){
		BinNodePosi(T) u = v->child[r+1];
		while(u->child[0]) u = u->child[0];
		v->key[r] = u->key[0]; v = u; r = 0;
	}
	v->key.remove(r); v->child.remove(r+1); _size--;
	solveUnderflow(v);
	return true;
}