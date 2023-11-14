#include <iostream>

template <class T>
class TStack {
    size_t size;
    T* data;
    size_t _top;
    TStack(): size(0), data(nullptr), _top(-1) {}
public:
    TStack(size_t _size) : size(_size), _top(-1) {
        data = new T[size];
    }
    TStack(const TStack& st): size(st.size), _top(st._top) {
        std::copy(data, st.data);
    }
    ~TStack() {
        delete[] data;
        data = nullptr;
    }

    bool isFull() {
        return (size == _top + 1);
    }
    bool isEmpty() {
        return (_top == -1);
    }

    T& top() {
        return data[_top];
    }
    void pop() {
        if (isEmpty()) throw std::logic_error "Stack is empty now";
        else _top--;
    }
    void push(const T& n) {
        if (isFull()) throw std::logic_error "Stack is full now";
        else data[++_top] = n;
    }
    void print() {
        for (int i = top; i > -1; i--) {
            std::cout << i << " " << data[i] << std::endl;
        }
    }
};