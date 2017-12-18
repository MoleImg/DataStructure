typedef int Rank;
#define DEFAULT_CAPACITY 3
template <typename T> class Vector {
protected:
	Rank _size; // effective volume
	int _capacity; // valid volume
	T* _elem;
	void copyFrom(T const* A, Rank lo, Rank hi);
	void expand(); // expand the volumn
	Rank insert(Rank r, T const &a); // insert
	void bubbleSort(Rank lo, Rank hi);
	bool bubble(Rank lo, Rank hi);
	void selectSort(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	static Rank binSearchV1(T* A, T const &e, Rank lo, Rank hi) const;
	static Rank binSearchV2(T* A, T const &e, Rank lo, Rank hi) const;
	static Rank binSearchV3(T* A, T const &e, Rank lo, Rank hi) const;
	static Rank fibSearch(T* A, T const &e, Rank lo, Rank hi) const;
public:
	// default constructor
	Vector(int c=DEFAULT_CAPACITY, int s=0, T v=0){
		_elem = new T[_capacity=c];
		for(_size=0; _size<s;_elem[_size++]=v);
	}
	// copy constructors
	Vector(T const *A, Rank lo, Rank hi) {copyFrom(A, lo, hi);}
	Vector(T const *A, Rank n) {copyFrom(A, 0, n);}
	Vector(Vector<T> const &V, Rank lo, Rank hi) {copyFrom(V._elem, lo, hi);}
	Vector(Vector<T> const &V) {copyFrom(V._elem, 0, V._size);}
	// destructor
	~Vector() {delete[] _elem;}

	// read-only interfaces
	T& operator[](Rank r) const; //overloading of "[]"
	Rank find(T const& e, Rank lo, Rank hi) const; //find single element in the range
	Rank find(T const& e) const; //find single element in the whole sequence
	Rank search(T const& e, Rank lo, Rank hi) const;
	int disordered() const; // quantify the disorderity of the vector

	// writable interfaces
	T remove(Rank r); //remove single element
	int remove(Rank lo, Rank hi); // remove range
	int deduplicate(); //for disordered vector
	int uniquify(); //for ordered vector
	void traverse(void (*visit)(T&)); //traverse the vector with the operation of (*visit) to each element
	void sort(Rank lo, Rank hi);
	void sort() {return sort(0, _size);}
	int size() {return _size;}
};