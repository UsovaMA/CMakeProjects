#include <iostream>
#include "stack.h"

template <class T>
TStack<T>::TStack(): size(0), data(nullptr), _top(-1) {}

template <class T>
TStack<T>::TStack(size_t _size) : size(_size), _top(-1) {
        data = new T[size];
    }
template <class T>
TStack<T>::TStack(const TStack& st): size(st.size), _top(st._top) {
        std::copy(data, st.data);
    }
template <class T>
TStack<T>::~TStack() {
        delete[] data;
        data = nullptr;
    }
template <class T>
bool TStack<T>::isFull() {
    return (size == _top + 1);
}
template <class T>
bool TStack<T>::isEmpty() {
    return (_top == -1);
}
template <class T>
T& TStack<T>::top() {
    return data[_top];
}
template <class T>
void TStack<T>::pop() {
    if (isEmpty()) throw std::logic_error "Stack is empty now";
    else _top--;
}
template <class T>
void TStack<T>::push(const T& n) {
    if (isFull()) throw std::logic_error "Stack is full now";
    else data[++_top] = n;
}
template <class T>
void TStack<T>::print() {
    for (int i = top; i > -1; i--) {
        std::cout << i << " " << data[i] << std::endl;
    }
}
