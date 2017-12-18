//LeftHeap.h
//Declaration of leftist heap
#include "PriorityQueue.h"
#include "BinTree.h"

template <typename T>
class LeftHeap : public PriorityQueue<T>, public BinTree<T>{
	void insert(T);
	T getMax(){ return _root->data; }
	T delMax();
}