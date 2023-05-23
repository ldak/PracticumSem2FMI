#pragma once
#include <iostream>

template <typename T>
class MyVector {
private:
    T* array;
    long long size = 0;
    long long capacity = 0;

    void copyFrom(const MyVector<T>& other);
    void free();
    void resize();
public:
    explicit MyVector(long long capacity);

    MyVector(const T* array, long long size, long long capacity);

    MyVector(const MyVector& other);

    MyVector& operator = (const MyVector& other);

    ~MyVector();

    void add(const T& arg);
    void add(long long position, const T& arg);
    void remove(long long positon);
    long long Size() const;
    void reverse();

    T operator[](long long i) const;
    T& operator[](long long i);

//    MyVector<T> filter(bool (predicate)(const T&)) const;
//
//    template <typename V>
//    V reduce(V(op)(const T&, V), V startpoint) const;
//
//    template <typename V>
//    MyVector<V> map(V(*op)(const T&)) const;

};
template <typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& vec) {
    for (long long i = 0; i < vec.Size(); i++)
    {
        os << vec[i];
    }
    return os;
}
