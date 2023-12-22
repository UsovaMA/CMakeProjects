#pragma once
#include<iostream>
template <class T>
class TNode {
	T data;
	TNode* next;
public:
	TNode(T _data, TNode* _next = nullptr) :
		data(_data), next(_next) { }
	TNode(const TNode& node): data(node.data), *next(node.next) {}
	TNode(T Tdata, TNode* Tnext = nullptr){
		this->data = Tdata;
		this->next = Tnext;
	}
	/*TNode(const T& value, TNode<T>* nextNode = nullptr) : data(value), next(nextNode) {}*/
	~TNode() {
	}
	
};