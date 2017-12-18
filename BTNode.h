//BTNode.h
//Declaration and implementation of B-tree node
#include "Vector.h"
#define BTNodePosi(T) BTNode*

template <typename T> struct BTNode{
	BTNodePosi(T) parent;
	Vector<T> key;
	Vector<BTNodePosi(T)> child;
//Constructors
	BTNode() {parent = NULL; child.insert(0, NULL);}
	BTNode(T e, BTNodePosi(T) lc = NULL, BTNodePosi(T) rc = NULL){
		parent = NULL;
		key.insert(0, e);
		child.insert(0, lc); child.insert(1, rc);
		if(lc) lc->parent = this; if(rc) rc->parent = this;
	}
};