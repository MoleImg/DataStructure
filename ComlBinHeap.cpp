//ComplBinHeap.cpp
//Implementation of completed binary heap
#include "ComlBinHeap.h"
#define parent(i) ((i-1) >> 1)
#define lChild(i) ((i << 1) + 1)
#define rChild(i) ((i + 1) << 1)


template <typename T>
Rank ComplBinHeap<T>::percolateUp(Rank i){
	while(parentValid(i){
		Rank j = Parent(i);
		if(lt(_elem[i], _elem[j])) break;
		swap(_elem[i], _elem[j]);
		i = j;
	}
	return i;
}


template <typename T>
void ComplBinHeap<T>::insert(T const e){
	Vector<T>::insert(e);
	percolateUp(_size-1);
}

template <typename T>
void ComplBinHeap<T>::percolateDown(int s, Rank r){
	Rank j;
	while(r != (j = properParent(_elem, s, r))){
		swap(_elem[i], _elem[j]);
		i = j;
	}
	return i;
}

template <typename T>
T ComplBinHeap<T>::delMax(){
	T maxElem = _elem[0];
	_elem[0] = _elem[--size];
	percolateDown(_size, 0);
	return maxElem;
}

template <typename T>
void ComplBinHeap<T>::heapify(Rank n){	//construct a heap by Floyd
	for(int i=LastInternal(n); i>=0; i--){
		percolateDown(n, i);
	}
}

template <typename T>
ComplBinHeap<T>::ComplBinHeap(T *A, Rank n){
	copyFrom(A, 0, n);
	heapify(n);
}

template <typename T>
void Vector<T>::heapSort(Rank lo, Rank hi){
	ComplBinHeap<T> H(_elem + lo, hi - lo);
	while(!H.empty()){
		_elem[--hi] = H.delMax();
	}
}