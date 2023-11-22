#include <iostream>

template <class T>
class TQueue {
    size_t size;
    T* tail;
    T* head;
    size_t last;
    TQueue() : size(0), tail(nullptr), head(nullptr), last(-1) {}
public:
    TQueue(_size) : size(_size), last(0) {
        tail = new T[size];
        head = new T[size];
    }

    bool isFull() {
        return (size == last + 1);
    }
    bool isEmpty() {
        return (last == -1);
    }

    void push(const T& elem) {
        if (!isFull()) {
            *tail = elem;
            tail++;
            head--;
        }
        else {
            std::logic_error "Queue is full";
        }
    }
    void reset() {
        if (!isEmpty()) {
            head--;
            tail++;
        }
        else {
            std::logic_error "Queue is empty";
        }
    }

};