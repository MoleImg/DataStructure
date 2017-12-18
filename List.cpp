//List.cpp
//Implementation of list
#include "List.h"

template <typename T>
void List<T>::init(){
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}

template <typename T>
int List<T>::clear(){
	int oldSize = _size;
	while(0<_size){
		remove(header->succ);
	}
	return oldSize;
}

template <typename T>
T& List<T>::operator[](Rank r){
	ListNodePosi(T) p = first();
	while(0<r--) p = p->succ;
	return p->data;
}

template <typename T>
ListNodePosi(T) List<T>::find(T const &e, int n, ListNodePosi(T) p) const{
	while(0<n--){
		if(e == (p=p->pred)->data) return p;
	}
	return NULL;

}

template <typename T>
ListNodePosi(T) List<T>::search(T const &e, int n, ListNodePosi(T) p) const{
	while(0<n--)
		if((p=p->pred)->data <= e) break; // return the last one who is not larger than e
	return p;

}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n){
	init();
	while(0<n--){
		insertAsLast(p->data);
		p = p->succ;
	}
}

template <typename T>
T List<T>::remove(ListNodePosi(T) p){
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template <typename T>
int List<T>::deduplicate(){
	if(_size<2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p = header;
	Rank r = 0;
	while(trailer != (p=p->succ)){
		ListNodePosi(T) q = find(p->data, r, p);
		q?remove(q):r++;
	}
	return oldSize - _size;
}

template <typename T>
int List<T>::uniquify(){
	if(_size<2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p = first();
	ListNodePosi(T) q;
	while(trailer != (q=p->succ)){
		if(p->data != q->data) p=q;
		else remove(q);
	}

	return oldSize - _size;
}

template <typename T>
int List<T>::deduplicate(){
	if(_size<2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p = header, q;
	Rank r = 0;
	while(trailer != (p=p->succ)){
		q = find(p->data, r, p);
		q?remove(q):r++;
	}

	return oldSize - _size;
}

template <typename T>
int List<T>::uniquify(){
	if(_size<2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p = first(), q;
	while(trailer != (q=p->succ)) {
		if(p->data != q->data) {p=q;}
		else {remove(q);}
	}

	return oldSize - _size;

}

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n){
	selectionSort(p, n);
}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n){
	ListNodePosi(T) head = p->pred, tail = p;
	for(int i=0; i<n; i++)
		tail = tail->succ;
	while(0<n){
		ListNodePosi(T) max = selecMax(head->succ, n);
		insertBefore(tail, remove(max));
		n--;
		tail = tail->pred;
	}
}

template <typename T>
ListNodePosi(T) List<T>::selecMax(ListNodePosi(T) p, int n){
	ListNodePosi(T) max = p;
	for(ListNodePosi(T) cur=p; 1<n; n--){
		if((cur=cur->succ)->data >= max) max = cur->data;
	}
	return max;
}

template <typename T>
void insertSort(ListNodePosi(T) p, int n){
	for(int i=0; i<n; i++){
		insertAfter(search(p->data, i, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}