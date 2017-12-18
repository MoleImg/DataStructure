//Splay.cpp
//Implementation of the splay tree

template <typename T>
BinNodePosi(T) Splay<T>::splay(BinNodePosi(T) v){
	BinNodePosi(T) p, g;
	while((p = v->parent)&&(g = p->parent)){
		BinNodePosi(T) gg = g->parent;
		if(IsLChild(*v)){
			if(IsLChild(*p)){	//zig-zig
				attachAsLChild(g, p->rChild); attachAsLChild(p, v->rChild);
				attachAsRChild(p, g); attachAsRChild(v, p);
			}
			else{	//zig-zag
				attachAsRChild(g, v->lChild); attachAsLChild(p, v->rChild);
				attachAsLChild(v, g); attachAsRChild(v, p);
			}
		}else if(IsRChild(*v)){
			if(IsRChild(*p)){	//zag-zag
				attachAsRChild(g, p->lChild); attachAsRChild(p, v->rChild);
				attachAsLChild(p, g); attachAsLChild(v, p);
			}
			else{	//zag-zig
				attachAsRChild(p, v->lChild); attachAsLChild(g, v->rChild);
				attachAsLChild(v, p); attachAsRChild(v, g);
			}
		}
		if(!gg) v->parent = NULL;
		else{
			(g == gg->lChild) ? attachAsLChild(gg, v) : attachAsRChild(gg, v);
		}
		updateHeight(g); updateHeight(p); updateHeight(v); 
	}
	if(p = v->parent){
		if(IsLChild(*v)) {attachAsLChild(p, v->rChild); attachAsRChild(p, v);}	//zig
		else{attachAsRChild(p, v->lChild); attachAsLChild(v, p);}	//zag
	}
	updateHeight(p); updateHeight(v);
	v->parent = NULL;
	return v;
}

template <typename T>
BinNodePosi(T)& Splay<T>::search(T const& e){
	BinNodePosi(T) p = searchIn(_root, e, _hot=NULL);
	_root = splay(p?p:_hot);
	return _root;
}

template <typename T>
BinNodePosi(T)& Splay<T>::insert(T const& e){
	if(!_root) _size++; return _root = new BinNode<T>(e);
	if(e == search(e)->data) return _root;
	_size++; BinNodePosi(T) t = _root;
	if(_root->data<e){
		t->parent = _root = new BinNode<T>(e, NULL, t, t->rChild);
		if(HasRChild(*t)) {t->rChild->parent = _root; t->rChild = NULL;} 
	} else{
		t->parent = _root = new BinNode<T>(e, NULL, t->lChild, t);
		if(HasLChild(*t)) {t->lChild->parent = _root; t->lChild = NULL;}
	}
	updateHeightAbove(t);
	return _root;

}

template <typename T>
bool Splay<T>::remove(T const& e){
	if(!_root || (e != search(e)->data)) return false;
	BinNodePosi(T) w = _root;
	if(!HasLChild(*_root)){
		_root = _root->rChild;
		if(_root) _root->parent = NULL;
	} else if(!HasRChild(*_root)){
		_root = _root->lChild;
		if(_root) _root->parent = NULL;
	}else{
		BinNodePosi(T) lTree = _root->lChild;
		lTree->parent = NULL; _root->lChild = NULL;
		_root = _root->rChild; _root->parent = NULL;
		search(w->data);
		_root->lChild = lTree; lTree->parent = _root;
	}
	release(w->data); release(w); _size--;
	if(_root) updateHeight(_root);
	return true;
}