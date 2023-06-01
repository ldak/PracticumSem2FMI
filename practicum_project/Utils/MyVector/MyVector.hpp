#pragma once
#include <iostream>

template <typename T>
class MyVector
{
private:
    T* m_data;
    int m_size;
    int m_capacity;

    void resize(int newCapacity);
    void free();
    void copyFrom(const MyVector<T>& other);
    void moveFrom(MyVector<T>&& other);
public:
    MyVector();
    explicit MyVector(int capacity);
    MyVector(const T* data, int size);
    MyVector(const MyVector<T>& other);
    MyVector& operator=(const MyVector<T>& other);
    ~MyVector();

    MyVector(MyVector<T>&& other) noexcept;
    MyVector<T>& operator=(MyVector<T>&& other) noexcept;

    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void clear();
    T& operator[](int index);
    T& operator[](int index) const;
    int size() const;
};

template<typename T>
MyVector<T>::MyVector(int capacity) {
    m_size = 0;
    m_capacity = capacity;
    m_data = new T[m_capacity];
}

template<typename T>
MyVector<T>::MyVector(const T *data, int size) {
    m_size = size;
    m_capacity = size;
    m_data = new T[m_capacity];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = data[i];
    }

}

template<typename T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other)  noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<typename T>
MyVector<T>::MyVector(MyVector<T> &&other) noexcept{
    moveFrom(std::move(other));
}

template<typename T>
void MyVector<T>::moveFrom(MyVector<T> &&other) {
    m_data = other.m_data;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template<typename T>
void MyVector<T>::push_back(T &&value) {
    if (m_size == m_capacity) {
        resize(m_capacity * 2);
    }
    m_data[m_size++] = std::move(value);

}


template<typename T>
void MyVector<T>::copyFrom(const MyVector<T> &other) {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new T[m_capacity];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = other.m_data[i];
    }
}


template<typename T>
void MyVector<T>::free() {
    delete[] m_data;

}

template<typename T>
void MyVector<T>::resize(int newCapacity) {
    T* temp = new T[newCapacity];
    for (int i = 0; i < m_size; i++) {
        temp[i] = m_data[i];
    }
    free();
    m_data = temp;
    m_capacity = newCapacity;

}

template<typename T>
T &MyVector<T>::operator[](int index) const {
    return m_data[index];
}

template<typename T>
int MyVector<T>::size() const {
    return m_size;
}

template<typename T>
T &MyVector<T>::operator[](int index) {
    return m_data[index];
}

template<typename T>
void MyVector<T>::clear() {
    free();
    m_size = 0;
    m_capacity = 8;
    m_data = new T[m_capacity];
}

template<typename T>
void MyVector<T>::pop_back() {
    if (m_size > 0) {
        m_size--;
    }
}

template<typename T>
void MyVector<T>::push_back(const T& value) {
    if (m_size == m_capacity) {
        resize(m_capacity * 2);
    }
    m_data[m_size++] = value;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T> &other) {
    copyFrom(other);
}

template<typename T>
MyVector<T>::~MyVector() {
    free();
}

template<typename T>
MyVector<T>::MyVector() {
    m_size = 0;
    m_capacity = 8;
    m_data = new T[m_capacity];
}
