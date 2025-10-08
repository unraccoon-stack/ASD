#pragma once
#include <stdexcept>


template <class T>
class Stack {
    T* _data;
    int _size, _top;
public:
    //Stack(int _size);
    void push(const T& val);
    void pop();
    inline T top() const;
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
    void clear() noexcept;
};

template <class T>
void Stack<T>::push(const T& val) {
    if (is_full()) {
        throw std::logic_error("stack is full");
    }
    _data[++_top] = val;
}

template <class T>
void Stack<T>::pop() {
    if (is_empty()) {
        throw std::logic_error("stack is empty");
    }
    --_top;
}

template <class T>
inline T Stack<T>::top() const {
    if (is_empty()) {
        throw std::logic_error("stack is empty");
    }
    return _data[_top];
}

template <class T>
inline bool Stack<T>::is_empty() const noexcept {
    return _top == -1;
}

template <class T>
inline bool Stack<T>::is_full() const noexcept {
    return _top == _size - 1;
}

template <class T>
void Stack<T>::clear() noexcept {
    _top = -1;
}
