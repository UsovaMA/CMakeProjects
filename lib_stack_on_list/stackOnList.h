#ifndef LIB_STACK_ON_LIST_STACKONLIST_H_
#define LIB_STACK_ON_LIST_STACKONLIST_H_

#include <string>
#include <iostream>
#include <format>
#include "../lib_list/list.h"
// сделать красивый принт в модуле сетв 
template<typename T>
class StackOnList {
private:
	List<T> data;
	size_t _size;
public:
	StackOnList() {
		_size = 0;
	}
	~StackOnList() { }
	void push(T val) {
		data.push_front(val);
		_size++;
	}
	void pop() {
		if (this->isEmpty())
			throw std::logic_error("stack on list is empty");
		data.pop_front();
		_size--;
	}
	T top() const {
		if (this->isEmpty())
			throw std::logic_error("stack on list is empty");
		return data.get_head();
	}
	void print() const {
		std::cout << this->toString();
	}
	std::string toString() const noexcept {
		std::string str = "";
		if (this->isEmpty())
			str = "<empty>";
		else {//форматирование
			Node<T>* current = data.begin();
			while (current != data.end()) {
				str += "|" + std::to_string(current->get_data()) + "|" + "\n";
				current = current->get_next();
			}
			str += "|" + std::to_string(current->get_data()) + "|" + "\n" + "-------" + "\n";
		}
		return str;
	}
	bool isEmpty() const {
		return data.isEmpty();
	}
	size_t size() const {
		return _size;
	}
};

#endif  // LIB_STACK_ON_LIST_STACKONLIST_H_
