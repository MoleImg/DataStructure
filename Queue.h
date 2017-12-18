//Queue.h
//Declaration of the queue structure
#include "List.h"

template <typename T> class Queue : public List<T>{
public:
	void enqueue(T const &e) {insertAsLast(e);}
	void dequeue() {return remove(first());}
	T& front() {return first()->data;}
};