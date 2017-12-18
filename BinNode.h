//BinNode.h
//Declaration and implementation of the BinNode structure

#define BinNodePosi(T) BinNode<T>*

template <typename T> struct BinNode
{
	BinNodePosi(T) parent, lChild, rChild;
	T data; int height; 
	int size();

//Constructors
	BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0) {}
	BinNode(T e, BinNodePosi(T) p=NULL, BinNodePosi(T) lc=NULL, BinNodePosi(T) rc=NULL, int h=0)
		:data(e), parent(p), lChild(lc), rChild(rc), height(h) {}
	BinNodePosi(T) insertAsLC(T const &);
	BinNodePosi(T) insertAsRC(T const &);
	BinNodePosi(T) succ();
	template <typename VST> void travLevel(VST &);
	template <typename VST> void travPre(VST &);
	template <typename VST> void travIn(VST &);
	template <typename VST> void travPost(VST &);
};

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e){
	return lChild = new BinNode(e, this);
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e){
	return rChild = new BinNode(e, this);
}

template <typename T>
int BinNode<T>::size(){
	int s = 1;
	if (lChild) s += lChild->size();
	if (rChild) s += rChild->size();
	return s;
}