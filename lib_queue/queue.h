#include <iostream>

template <class T>
class TQueue {
    size_t size;
    T* tail;
    T* head;
    size_t last;
    TQueue();
 public:
     TQueue(_size);

     bool isFull();
     bool isEmpty();

     void push(const T& elem);
     void reset();
};

