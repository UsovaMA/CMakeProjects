#include <iostream>

template <class T>
class TStack {
    size_t size;
    T* data;
    size_t _top;
    TStack();
 public:
    TStack(size_t _size);
    TStack(const TStack& st);
    ~TStack();

    bool isFull();
    bool isEmpty();

    T& top();
    void pop();
    void push(const T& n);
    void print();
};