#pragma once
#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_
#include<iostream>
#include <stdexcept>
template <class T> class TStack;
template <class T> std::ostream& operator<<(std::ostream& out,
    const TStack<T>& st) {}
template<class T>
class TStack {
    size_t _size;
    size_t _top;
    T* data;
 public:
    TStack(size_t sz) :_size(sz), _top(-1);
    TStack(const TStack& st) :_size(st._size), _top(st._top);
    ~TStack();
    bool isFull();
    bool isEmpty();
    T& top();
    void pop();
    void push(const T& a);
    friend std::ostream& operator<< <T>(std::ostream& out, const TStack<T>& st);
};
#endif