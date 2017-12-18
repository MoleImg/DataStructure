//ComplBinHeap.h
// Declaration of completed binary heap
#include "PriorityQueue.h"
#include "Vector.h"

template <typename T> class ComplBinHeap 
	: public PriorityQueue<T>, public Vector<T>{
protected:
	void percolateUp(Rank);
	void percolateDown(int, Rank);
public:
	ComplBinHeap(T*, Rank);
	void insert(T);
	T getMax();
	T delMax();
}