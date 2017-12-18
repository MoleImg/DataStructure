//List.h
//Declaration of the list
#include "ListNode.h"
#define int Rank
template <typename T> class List{
private:
	int _size;
	ListNodePosi<T> header;
	ListNodePosi<T> trailer;
protected:
	void init();
	int clear(); // clear all the visible nodes
	void selectionSort(ListNodePosi(T) p, int n);
	ListNodePosi(T) selecMax(ListNodePosi(T) p, int n);
	void insertSort(ListNodePosi(T) p, int n);
public:
	//constructors
	List(){init();}
	List(List<T> const &L); //copy constructor
	List(List<T> const &L, Rank r, int n); //copy constructor
	List(ListNodePosi<T> p, int n); //copy constructor
	//destructor
	~List(){clear(); delete header; delete trailer;}
	//read only interfaces
	T& operator[](Rank r) const; // call by rank
	ListNodePosi(T) find(T const &e, int n, ListNodePosi(T) p) const; //find in the range of disordered list
	ListNodePosi(T) search(T const &e, int n, ListNodePosi(T) p) const; //for ordered only
	ListNodePosi(T) first() const {return header->succ;}
	ListNodePosi(T) last() const {return trailer->pred;}

	//writable interfaces
	ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const &e){
		_size++;
		return p->insertAsPred(e);
	}
	ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const &e){
		_size++;
		return p->insertAsSucc(e);
	}
	ListNodePosi(T) insertAsLast(T const &e){
		return insertBefore(trailer, e);
	}

	void copyNodes(ListNodePosi(T) p, int n);
	T remove(ListNodePosi(T) p);
	int deduplicate(); //for disodered only
	int uniquify(); //for ordered only
	void sort(ListNodePosi(T) p, int n);


	
};