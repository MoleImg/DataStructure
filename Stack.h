//Stack.h
//Declaration of Stack
#include "Vector.h"
#include "List.h"

template <typename T> class StackFromVector:public Vector<T>{
	void push(T const &e) {insert(size(), e);}
	T pop() {return remove(size()-1);}
	T& top() {return (*this)[size()-1];} // get the top element, not the address
	//size() and empty() can be used from the based class

};

template <typename T> class StackFromList:public List<T>{
	void push(T const &e) {insertAsLast(e);}
	T pop() {return remove(last());}
	T& top() {return last()->data;}
};

//Applications
// scale conversion
int scaleConv(int decNum, int scale){
	StackFromList sfl();
	while(decNum!=0){
		sfl.push(decNum%scale);
		decNum /= scale;
	}
	int result = 0;
	while(sfl.size()>0)
		result = result*10+sfl.pop();

	return result;
}
// bracket matching
bool paren(const char exp[], int lo, int hi){//exp[lo,hi)
	StackFromList sfl();
	for(int i=lo; i<hi; i++){
		switch(exp[i]):
		case "(":case "[":case "{": sfl.push(exp[i]); break;
		case ")": if(sfl.empty() || sfl.pop()!="(") return false; break;
		case "]": if(sfl.empty() || sfl.pop()!="[") return false; break;
		case "}": if(sfl.empty() || sfl.pop()!="{") return false; break;

		default: break; //non-bracket
	}
	return sfl.empty(); //if false, left more than right
}