// PriorityQueue.h
//Interface of all the priority queues

template <typename T> struct PriorityQueue{
	virtual void insert(T) = 0;
	virtual T getMax() = 0;
	virtual T delMax() = 0;
}