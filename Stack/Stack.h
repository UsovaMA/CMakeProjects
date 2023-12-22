#pragma once

#include<iostream>

template <class T>
class TStack {
	size_t size; //натуралньое целое число размер стэка
	T* data; //массив 
	size_t _top; //число где находится последний элемент
	TStack() : size(0), data(nullptr), _top(-1) {}
public:
	TStack(size_t _size) : size(_size), _top(-1) { //коструктор принимающий на вход размер стэка
		data = new T[size];
	}
	TStack(const TStack& st) :size(st.size), _top(st._top) { //конструктор копирования
		std::copy(data, st.data); //функция копирования даты из ст дата
	}
	//деструктор
	~TStack() {
		delete[] data;
		data = nullptr;
	}
	bool isFull() { //полный стэк или нет
		return size == _top + 1; //индексирование начинается с 0 поэтому +1
	}
	bool isEmpty() { //пустой ли стэк
		return _top == -1;
	}

	T& top() {
		if (isEmpty()) 
			throw std::out_of_range("error");
		return data[_top];
	}
	void pop() { //взять элемент из верха
		if (isEmpty()) {
			throw std::out_of_range("error");
		}
		else {
			_top--; //удаляем элемент но никуда не присваиваем
		}
	}
	void push(const T& n) {
		if (isFull()) {
			throw std::out_of_range("error");
		}
		data[++_top] = n;
	}
	void Print() {
		for (int i = top; i > -1; i--) {
			std::cout << i << "" << data[i] << std::endl;
		}
	}
};