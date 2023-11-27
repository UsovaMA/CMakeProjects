#ifndef LIB_LIST_LIST_H_
#define LIB_LIST_LIST_H_

#include <string>
#include <iostream>
//сделать тесты на лист он стэк вначале записи
template <class T> class Node;

template <class T> class List;

template<typename T>
class Node {
private:
	T data;
	Node<T>* next;
public:
	Node() {
		data = NULL;
		next = nullptr;
	}
	Node(T _data, Node<T>* _next = nullptr) : data(_data), next(_next){}
	void print() const noexcept {
		std::cout << toString();
	}
	std::string toString() const noexcept {
		std::string str = "";
		if(data != NULL)
		    str = std::to_string(data) + "->";
		if (next == nullptr)
			str += "NULL";
		return str;
	}
	Node<T>& operator=(const Node<T>& other) {
		data = other.data;
		next = other.next;
	}
	bool operator==(const Node<T>& other) {
		return (data == other.data);
	}
	bool operator!=(const Node<T>& other) {
		return (data != other.data);
	}
	bool operator<(const Node<T>& other) {
		return(this->get_data() < other.get_data());
	}
	bool operator>(const Node<T>& other) {
		return(this->get_data() > other.get_data());
	}
	friend class List<T>;
	//добавить больше меньше 
	T get_data() const {
		return data;
	}
	Node<T>* get_next() const {
		return next;
	}
};


template<typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List() : head(nullptr), tail(nullptr){}
	~List(){
		this->clear();
	}
	void clear() {
		while (!this->isEmpty()) {
			this->pop_front();
		}
		//this->head = nullptr;
		//this->tail = nullptr;
	}
	void insert(Node<T>* pos, T data) {
		if (pos == nullptr) {
			throw std::logic_error("given position is nullptr");
		}
		Node<T>* new_node = new Node<T>(data, pos->next);
		pos->next = new_node;
		if (pos == tail) {
			tail = new_node;
		}
	}
	void push_back(T data) {
		if (isEmpty()) {
			Node<T>* new_node = new Node<T>(data, nullptr);
			head = new_node;
			tail = new_node;
		}
		else
			insert(tail, data);
	}
	void push_front(T data) {
		Node<T>* new_node = new Node<T>(data, head);
		if (isEmpty()) {
			tail = new_node;
		}
		head = new_node;
	}
	void erase(Node<T>* pos) {
		if (isEmpty())
			throw std::logic_error("List is empty");
		if (pos == nullptr) 
			throw std::logic_error("given position is nullptr");
		if (pos == head) {
			if (head == tail) {
				tail = nullptr;
			}
			head = head->next;
			delete pos;
		}
		else {
			Node<T>* current = head;
			while (current->next != pos) {
				current = current->next;
			}
			current->next = current->next->next;
			if (pos == tail) {
				tail = current;
			}
			delete pos;
		}
	}
	void pop_back() {
		erase(tail);
	}
	void pop_front() {
		erase(head);
	}
	bool isEmpty() const {
		return head == nullptr;
	}
	void print() const {
		Node<T>* current = head;
		if (current == nullptr)
			std::cout << "Empty";
		while (current != nullptr) {
			current->print();
			current = current->next;
		}
		std::cout << std::endl;
	}
	T get_head() const {
		if (this->isEmpty())
			throw std::logic_error("list is empty");
		return head->data;
	}
	Node<T>* begin() const {
		return head;
	}
	Node<T>* end() const {
		return tail;
	}
};
#endif  // LIB_LIST_LIST_H_