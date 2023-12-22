#pragma once
#include<iostream>
template <class T>
class TNode {
public:
	T data;
	TNode* next;

	TNode(T _data, TNode* _next = nullptr) :
		data(_data), next(_next) { }
	TNode(const TNode& node) : data(node.data), * next(node.next) {}
	/*TNode(T Tdata, TNode* Tnext = nullptr) {*/
	/*	this->data = Tdata;
		this->next = Tnext;
	}*/
	/*TNode(const T& value, TNode<T>* nextNode = nullptr) : data(value), next(nextNode) {}*/
	~TNode() {
	}

};
template <class T>
class TList {
	friend class TNode<T>;
	TNode<T>* head;
	TNode<T>* tail;
	int count;
public:
	//итераторы
	TList() : head(nullptr), tail(nullptr), count(0){};
	TList(T* massData, int size)//массив преобраз. в список 
	{
		for (size_t i = 0; i < size; i++) {
			push_back(massData[i]);
		}
	}
	
	~TList() {
		TNode<T>* currentNode = head;
		while (currentNode != nullptr) {
			TNode<T>* toDelete = currentNode;
			currentNode = currentNode->next;
			delete toDelete;
		}
		head = nullptr;
		tail = nullptr;
	}
	bool isEmpty() {
		return head == nullptr;
	}
	void push_back(const T& Tdata) {
		if (isEmpty()) {
			push_front(Tdata);
		}
		else {
			TNode<T>* newNode = new TNode<T>(Tdata, nullptr);
			tail->next = newNode;
			tail = newNode; // Update the tail pointer
		}
		count++;
	}
	void push_front(T Tdata) {
		TNode<T>* node = new TNode<T>(Tdata, head);
		head = node;
		count++;
		if (count == 1)
		tail = node;
	}
	void insert(TNode<T>* p, const T& Tdata) {
		if (p == nullptr) {
			push_front(Tdata);
			return;
		}
		else if (p == tail) {
			push_back(Tdata);
			return;
		}
		else {
			TNode<T>* newNode = new TNode<T>(Tdata, p->next);
			p->next = newNode;
			count++;
		}
	}
	void replace(TNode<T>* p,T Tdata) {
		p->data = Tdata;
	}
	void deleteNode(TNode<T>* p) {
		if (p == head) {
			head = p->next;
			delete p;
			if (head == nullptr) {
				tail = nullptr;
			}
			return;
		}

		TNode<T>* cur = head;
		while (cur != nullptr && cur->next != p) {
			cur = cur->next;
		}

		if (cur != nullptr) {
			cur->next = p->next;
			if (cur->next == nullptr) {
				tail = cur;
			}
			delete p;
		}
	}
	
	//void clear();

};
