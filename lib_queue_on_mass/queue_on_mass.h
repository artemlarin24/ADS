// Copyright 2026 artemlarin24
#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class TQueueOnMass {
 private:
    T* _data;
    size_t _size;
    size_t _count;
    size_t _front;
    size_t _back;

 public:
    explicit TQueueOnMass(size_t size = 1);
    TQueueOnMass(const TQueueOnMass& other);
    ~TQueueOnMass();

    void push(const T& element);
    T pop();
    T& front();

    size_t size() const noexcept;
    bool is_empty() const noexcept;
    bool is_full() const noexcept;
};

template <typename T>
TQueueOnMass<T>::TQueueOnMass(size_t size)
    : _data(nullptr), _size(size), _count(0), _front(0), _back(0) {
    if (size == 0) {
        throw std::invalid_argument("Queue size must be positive");
    }
    _data = new T[_size];
}

template <typename T>
TQueueOnMass<T>::TQueueOnMass(const TQueueOnMass& other)
    : _data(new T[other._size]),
    _size(other._size),
    _count(other._count),
    _front(other._front),
    _back(other._back) {
    for (size_t i = 0; i < _count; ++i) {
        size_t index = (_front + i) % _size;
        _data[index] = other._data[index];
    }
}

template <typename T>
TQueueOnMass<T>::~TQueueOnMass() {
    delete[] _data;
}

template <typename T>
void TQueueOnMass<T>::push(const T& element) {
    if (is_full()) {
        throw std::overflow_error("Queue is full");
    }

    _data[_back] = element;
    _back = (_back + 1) % _size;
    ++_count;
}

template <typename T>
T TQueueOnMass<T>::pop() {
    if (is_empty()) {
        throw std::underflow_error("Queue is empty");
    }

    T result = _data[_front];
    _front = (_front + 1) % _size;
    --_count;
    return result;
}

template <typename T>
T& TQueueOnMass<T>::front() {
    if (is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    return _data[_front];
}

template <typename T>
size_t TQueueOnMass<T>::size() const noexcept {
    return _size;
}

template <typename T>
bool TQueueOnMass<T>::is_empty() const noexcept {
    return _count == 0;
}

template <typename T>
bool TQueueOnMass<T>::is_full() const noexcept {
    return _count == _size;
}
