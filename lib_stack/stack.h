#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_
#include <iostream>

template <class T>
class Stack {
    size_t size;
    T* data;
    size_t top;


public:
    Stack() : size(0), data(nullptr), top(-1) { }

    Stack(int size_) {
        size = size_;
        top = -1;
        data = new T[size];
    }
    Stack(const Stack& st) {
        size = st.size;
        top = st.top;
        data = new T[size];
        for (int i = 0; i < size; i += 1) {
            data[i] = st.data[i];
        }
    }
    ~Stack() {
        delete[]data;
        data = nullptr;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return size == top + 1;
    }
    T& getTop() {
        return data[top];
    }
    void pop() {
        if (isEmpty()) {
            throw std::logic_error("Stack is empty!");
        }
        top--;
    }
    void push(T elem) {
        if (isFull()) {
            throw std::logic_error("Stack is full!");
        }
        top++;
        data[top] = elem;
    }

    void print() {
        Stack copy(*this);
        while (!copy.isEmpty()) {
            std::cout << copy.getTop() << '\n';
            copy.pop();
        }
    }
};
#endif  // LIB_STACK_STACK_H_