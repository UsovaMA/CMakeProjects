// Copyright 2023 Aleksey Lavrentyev

#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H_

#include <string>
#include <iostream>
//вначале посмотреть как исправить удаление, можно добавить фронт
template <class T> class Queue;

template<typename T>
class Queue {
private:
    T* data;
    int _back;
    int _size;
public:
    Queue(int __size) : _size(__size), _back(-1) {
        if (_size <= 0)
            throw std::length_error("size is positive value");
        data = new T[_size];
    }
    ~Queue() {
        delete[] data;
        data = nullptr;
    }
    int size() const {
        return _size;
    }
    void push(T val) {
        if (isFull())
            throw std::logic_error("queue is full");
        _back++;
        data[_back] = val;
    }
    void pop() {
        if (isEmpty())
            throw std::logic_error("queue is empty");
        for (int i = 0; i < _back; i++) {
            data[i] = data[i + 1];
        }
        _back--;
    }
    T back() const {
        if (isEmpty())
            throw std::logic_error("queue is empty");
        return data[_back];
    }
    T front() const {
        if (isEmpty())
            throw std::logic_error("queue is empty");
        return data[0];
    }
    void print() const {
        std::cout << this->toString();
    }
    bool isFull() const {
        return (_back == _size - 1);
    }
    bool isEmpty() const {
        return (_back == -1);
    }
    std::string toString() const noexcept {
        std::string str = "";
        if (isEmpty())
            str = "<empty>";
        else {
            for (int i = 0; i <= _back; i++) {
                str += std::to_string(data[i]) + "\n";
            }
        }
        return str;
    }
};

#endif  // LIB_QUEUE_QUEUE_H
