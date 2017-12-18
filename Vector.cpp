// Vector.cpp
// Implementation of Vector
# include "Vector.h"

template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2*(hi-lo)];
	while(lo<hi)
		_elem[_size++] = A[lo++];
}

template <typename T>
void Vector<T>::expand() {
	if (_size<_capacity) return;
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
	T *oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for(int i=0; i<_size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem; // release the original space
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const &a) {
	expand();
	int i=_size;
	for(i;i>r;i--){
		_elem[i] = _elem[i-1];
	}
	_elem[r] = a;
	_size++;
	return r;
}

template <typename T>
T& Vector<T>::operator[](Rank r) const {
	return _elem[r];
}

template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const {
	while ((lo<hi--) && (e != _elem[hi]));
	return hi;
}

template <typename T>
Rank Vector<T>::find(T const &e) const {
	return find(e, 0, (Rank)_size);
}

template <typename T>

Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const {
	return binSearchV3(_elem, e, lo ,hi);
}

template <typename T>
static Rank Vector<T>::binSearchV1(T* A, T const &e, Rank lo, Rank hi) const {
	while(lo<hi){
		Rank mid = (lo+hi)/2;
		if (e<A[mid]) hi = mid;
		else if (A[mid]<e) lo = mid+1;
		else return mid;
	}
	return -1;
}

template <typename T>
static Rank Vector<T>::binSearchV2(T* A, T const &e, Rank lo, Rank hi) const {
	while(1<(hi-lo)){
		Rank mid = (lo+hi)/2;
		if (e<A[mid]) hi = mid;
		else lo = mid;
	}
	return (e == A[lo])?lo:-1;
}

template <typename T>
static Rank Vector<T>::binSearchV3(T* A, T const &e, Rank lo, Rank hi) const {
	while(lo<hi){
		Rank mid = (lo+hi)/2;
		if (e<A[mid]) hi = mid;
		else lo = mid+1;
	}
	return --lo;
}

template <typename T>
int Vector<T>::disordered() const {
	int n = 0, i=1;
	for(i;i<_size;i++)
		if (_elem[i-1]>_elem[i]) n++;
	return n;
}

template <typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	int i=r;
	for(i;i<_size-1;i++){
		_elem[i] = _elem[i+1];
	}
	_size--;
	return e;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while(hi<_size)
		_elem[lo++] = _elem[hi++];
	_size = lo;

	return (hi - lo);
}

template <typename T>
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i=1;
	while(i<_size)
		(find(_elem[i], 0, i)<0)?i++:remove(i);
	return oldSize - _size;
}

template <typename T>
int Vector<T>::uniquify() {
	int i=0, j=0;
	while(++j<_size)
		if(_elem[i] != _elem[j]) _elem[++i] = _elem[j];
	_size = ++i;
	return j - i;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T&)) {
	for (int i=0; i<_size; i++)
		visit(_elem[i]);
}

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
	return bubbleSort(lo, hi);
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while(lo<(hi=bubble(lo, hi--)));
}

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
	Rank pos = lo;
	while(++lo<hi){
		if(_elem[lo-1]>_elem[lo]) {
			swap(_elem[lo-1], _elem[lo]);
			pos = lo;
		}
	}
	return pos;
}

template <typename T>
void Vector<T>::quickSort(Rank lo, Rank hi){
	if((hi - lo) < 2) return;
	Rank mi = partition(lo, hi-1);
	quickSort(lo, mi);
	quickSort(mi+1, hi);
}

