//LeftHeap.cpp
//Implementation of leftist heap
#include "LeftHeap.h"

template <typename T>
static BinNodePosi(T) merge(BinNodePosi(T) a, BinNodePosi(T) b){
	if(!a) return b;
	if(!b) return a;
	if(lt(a->data, b->data)) swap(b, a);
	a->rc = merge(a->rc, b);
	a->rc->parent = a;
	if(!a->rc || a->lc->npl < a->rc->npl)
		swap(a->lc, a->rc);
	a->npl = a->rc ? a->rc->npl+1 : 1;
	return a;
}

template <typename T>
void LeftHeap<T>::insert(T e){
	BinNodePosi(T) v = new BinNode<T>(e);
	_root = mearge(_root, v);
	_root->parent = NULL;
	_size++;
}

template <typename T>
T delMax(){
	BinNodePosi(T) lHeap = _root->lc;
	BinNodePosi(T) rHeap = _root->rc;
	T maxElem = _root->data;
	delete _root; _size--;
	_root = merge(lHeap, rHeap);
	if(_root) _root->parent = NULL;
	return maxElem;
}

