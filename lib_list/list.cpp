#include <iostream>
#include "list.h"

template <class T>
TNode<T>::TNode(const TNode& node) {
	data = node.data;
	*next = node->next;
}
	TNode(T _data, TNode* _next = nullptr) {
		this->data = _data;
		this->next = _next;
	}
	~TNode() {
		delete next;
	}
	int operator==(const TNode& node) const {
		if (data == node.data) return true;
		else return false;
	}
	TNode& operator=(const TNode& node) {
		data = node.data;
		this->next = node->next;
	}
	friend std::ostream& operator<<(std::ostream out, const TNode& node);
};

template <class T>
std::ostream& operator<<(std::ostream out, const TNode<T>& node) {
	out << "Текущий элемент: " << node.data << std::endl;
	return out;
}

template <class T>
class TList {
	friend class TNode;
	TNode* head;
	TNode* tail;
	int count;
public:
	//итераторы
	TList() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	TList(T* massData, int size) {
		//реализовать используя вставку
		for (int i = 0; i < size; i++) {
			push_back(mass[i]);
		}
	}
	~TList() {
		delete head;
		delete tail;
		//nullptr
	}
	bool isEmpty();

	void push_back(T data);
	void push_front(T data);
	void insert(TNode* p, T data);

	void reset_back();
	void reset_front();
	void reset(TNode* p);

	void replace(TNode* p, T data);

	void clear();

	void insert_mass(T* mass, int size, TNode* p);
	void reset_mass(TNode* from, TNode* to);
};

bool TList<T>::isEmpty() {
	if (head == nullptr) return true;
	else return false;
}

void push_back(T data) {
	insert(tail, data);
}

void push_front(T data) {
	TNode* node = new TNode(data, head);
	head = node;
	count++;
	if (count == 1) {
		tail = head;
	}
}

void insert(TNode* p, T data) {
	TNode* node = new TNode(data, p->next);
	p->next = node;
	count++;
	if (node->next == nullptr) {
		tail = data;
	}
}

void reset_back() {
	reset(tail);
}

void reset_front() {
	reset(head);
}

void reset(TNode *p) {
	if (p == head) {
		if (head == nullptr) tail = nullptr;
		head = p->next;
		delete p;
		return 0;
	}
	TNode* cur = head;
	while (cur->next != p && cur->next != nullptr) {
		cur = cur->next;
		cur->next = cur->next->next;
		delete p;
	}
	if (cur->next == nullptr) {
		tail = cur;
	}
	count--;
}

void replace(TNode* p, T data) {
	p->data = data;
}

void clear() {
	while (head != nullptr) {
		TNode* tmp = head;
		delete tmp;
		head = tmp->next;
	}
	delete head;
}

void insert_mass(T* mass, int size, TNode* p) {
	for (int i = 0; i < size; i++) {
		data = mass[i];
		p = mass;
	}
}

void reset_mass(TNode* from, TNode* to) {

}