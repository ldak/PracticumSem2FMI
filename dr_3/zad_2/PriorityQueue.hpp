#pragma once

#include "MyVector.hpp"
#include "Queue.hpp"

template <typename T>
class PriorityQueue
{
    MyVector<MyQueue<T>> queues;
    int queueSize = 0;
public:
    explicit PriorityQueue(int k);
    void push(const T& obj, int priority);
    void push(T&& obj, int priority);
    void pop();

    const T& peek() const;
    bool isEmpty() const;
};

template<typename T>
bool PriorityQueue<T>::isEmpty() const {
    for (int i = this->queueSize - 1; i >= 0; --i) {
        if (!this->queues[i].isEmpty()) {
            return false;
        }
    }
    return true;
}

template<typename T>
const T &PriorityQueue<T>::peek() const {
    for (int i = this->queueSize - 1; i >= 0; --i) {
        if (!this->queues[i].isEmpty()) {
            return this->queues[i].peek();
        }
    }
}

template<typename T>
void PriorityQueue<T>::pop() {
    for (int i = this->queueSize - 1; i >= 0; --i) {
        if (!this->queues[i].isEmpty()) {
            this->queues[i].pop();
            return;
        }
    }

}

template<typename T>
void PriorityQueue<T>::push(T &&obj, int priority) {
    if (priority >= this->queueSize) {
        throw std::out_of_range("Invalid priority");
    }
    this->queues[priority].push(std::move(obj));
}

template<typename T>
void PriorityQueue<T>::push(const T &obj, int priority) {
    if (priority >= this->queueSize) {
        throw std::out_of_range("Invalid priority");
    }
    this->queues[priority].push(obj);
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int k) {
    this->queueSize = k;
    this->queues = MyVector<MyQueue<T>>(k);

}
