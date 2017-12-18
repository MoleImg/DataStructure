//BinTree.h
//Declaration of the Binary Tree
#include "BinNode.h"
#include "Stack.h"
#define stature(p) ((p)?(p)->height:-1)

template <typename T> class BinTree
{
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T) x); // update the height of x
	void updateHeightAbove(BinNodePosi(T) x); // update the height of x and its ancester
	template <typename VST>
	void visitAlongLeftBranch(BinNodePosi(T), VST &visit, Stack<BinNodePosi(T)> &s);
	void goAlongLeftBranch(BinNodePosi(T), Stack<BinNodePosi(T)> &s);
public:
// Constructors
	BinTree(arguments);
	~BinTree();
// Read-only interfaces
	int size() const { return _size; }
	bool empty() const { return !_root; }
	BinNodePosi(T) root() const { return _root; }

// Writable interfaces
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e);
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e);
	template <typename VST>
	void travePre(BinNodePosi(T) x, VST &visit);  // preorder traverse
	template <typename VST>
	void traveIn(BinNodePosi(T) x, VST &visit); // inorder traverse
};

template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x){
	return x->height = 1 + max(stature(x->lChild), stature(x->rChild));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x){
	while(x)
		{updateHeight(x); x = x->parent;}
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e){
	_size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rChild;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const &e){
	_size++;
	x->insertAsLC(e);
	updateHeightAbove(x);
	return x->lChild;
}

template <typename T, typename VST>
void BinTree<T>::visitAlongLeftBranch(BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> s){
	while(x){
		visit(x->data);
		if(NULL != x->rChild)
			s.push(x->rChild);
		x = x->lChild;
	}
}

template <typename T, typename VST>
void BinTree<T>::travePre(BinNodePosi(T) x, VST &visit){
	Stack<BinNodePosi(T)> s;
	while(true){
		visitAlongLeftBranch(x, visit, s);
		if(s.empty()) break;
		x = s.pop();
	}
}

template <typename T>
void BinTree<T>::goAlongLeftBranch(BinNodePosi(T), Stack<BinNodePosi(T)> s){
	while(x){
		s.push(x);
		x = x->lChild;
	}
}

template <typename T, typename VST>
void BinTree<T>::traveIn(BinNodePosi(T) x, VST &visit){
	Stack<BinNodePosi(T)> s;
	while(true){
		goAlongLeftBranch(x, s);
		if(s.empty()) break;
		x = s.pop();
		visit(x->data);
		x = x->rChild;
	}
}
