// Copyright 2023 Aleksey Lavrentyev

#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_
#include <string>
#include <iostream>

template <class T> class Stack;

template<typename T>
class Stack {
private:
    T* data;
    int _top;
    int _size;
public:
    Stack(int __size) : _size(__size), _top(-1) {
        if (_size <= 0)
            throw std::length_error("size is positive value");
        data = new T[_size];
    }
    ~Stack() {
        delete[] data;
        data = nullptr;
    }
    int size() const {
        return _size;
    }
    void push(T val) {
        if (isFull())
            throw std::logic_error ("stack is full");
        _top++;
        data[_top] = val;
    }
    void pop() {
        if (isEmpty())
            throw std::logic_error("stack is empty");
        _top--;
    }
    T top() const {
        if (isEmpty())
            throw std::logic_error("stack is empty");
        return data[_top];
    }
    void print() const {
        std::cout << this->toString();
    }
    bool isFull() const {
        return (_top == _size - 1);
    }
    bool isEmpty() const {
        return (_top == -1);
    }
    std::string toString() const noexcept {
        std::string str = "";
        if (isEmpty())
            str = "<empty>";
        else {
            for (int i = _top; i > -1; i--) {
                str += std::to_string(data[i]) + "\n";
            }
        }
        return str;
    }
};

#endif  // LIB_STACK_STACK_H_
