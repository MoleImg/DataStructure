//ListNode.h
//Declaration of the list node
#define ListNodePosi(T) ListNode<T>*
template <typename T> struct ListNode{
	T data; //value
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;
	ListNode(){}
	ListNode(T e, ListNodePosi(T) p=NULL, ListNodePosi(T) s=NULL):data(e), pred(p), succ(s){}
	ListNodePosi(T) insertAsPred(T const &e);
	ListNodePosi(T) insertAsSucc(T const &e);

};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const &e){
	ListNodePosi(T) newNode = new ListNode(e, pred, this);
	pred->succ = newNode;
	pred = newNode;
	return newNode;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const &e){
	ListNodePosi(T) newNode = new ListNode(e, this, succ);
	succ->pred = newNode;
	succ = newNode;
	return newNode;
}