#pragma once
#include <cstring>
#include <iostream>

template <typename T>
class MyVector {
private:
    T* _array;
    size_t _size = 0;
    size_t _capacity = 0;

    void copyFrom(const MyVector<T> &other);
    void free();
    void resize();
public:
    explicit MyVector(size_t capacity);

    MyVector(const T* array, size_t size, size_t capacity);

    MyVector(const MyVector& other);

    MyVector& operator = (const MyVector& other);

    ~MyVector();

    void add(const T& arg);
    void add(size_t position, const T& arg);
    void remove(size_t positon);
    size_t Size() const;
    void reverse();

    T operator[](size_t i) const;
    T& operator[](size_t i);

    MyVector<T> filter(bool (predicate)(const T&)) const;

    template <typename V>
    V reduce(V(op)(const T&, V), V startpoint) const;

    template <typename V>
    MyVector<V> map(V(*op)(const T&)) const;

};
template <typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& vec) {
    for (size_t i = 0; i < vec.Size(); i++)
    {
        os << vec[i];
    }
    return os;
}
