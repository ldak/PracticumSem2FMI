#include "MyVector.h"

template class MyVector<int>;

template <typename T>
MyVector<T>::MyVector(long long capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->array = new T[capacity];
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector<T> &other)
{
    this->array = new T[other.capacity];
    for (long long i = 0; i < other.size; i++)
    {
        this->array[i] = other.array[i];
    }
    this->size = other.size;
    this->capacity = other.capacity;
}

template <typename T>
void MyVector<T>::free() {
    delete[] this->array;
}

template <typename T>
MyVector<T>::MyVector(const T* array, const long long size, const long long capacity)
{
    this->size = size;
    this->capacity = capacity;
    this->array = new T[capacity];
    for (long long i = 0; i < size; i++)
    {
        this->array[i] = array[i];
    }

}

template <typename T>
MyVector<T>::MyVector(const MyVector &other)
{
    copyFrom(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator = (const MyVector<T>& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    free();
}

template <typename T>
void MyVector<T>::add(const T& arg)
{
    if (size == capacity) {
        resize();
    }
    array[size++] = arg;
}

template <typename T>
void MyVector<T>::add(long long position, const T& arg) {
    if (position >= capacity) {
        return;
    }
    array[position] = arg;
}

template <typename T>
void MyVector<T>::remove(long long position) {
    if (position >= size) {
        return;
    }

    for (long long i = position+1; i < size; i++)
    {
        array[i - 1] = array[i];
    }
    size -= 1;
}

template <typename T>
long long MyVector<T>::Size() const{
    return size;
}

template <typename T>
void MyVector<T>::reverse() {
    T* temp = new T[capacity];
    for (long long i = 0; i < size; i++)
    {
        temp[i] = array[size - i - 1];
    }
    delete[] array;
    array = temp;
}

template <typename T>
void MyVector<T>::resize() {
    T* temp = new T[capacity * 2];
    for (long long i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    capacity = capacity * 2;
    delete[] array;
    array = temp;
}
template <typename T>
T& MyVector<T>::operator[](long long i) {
    return array[i];
}

template <typename T>
T MyVector<T>::operator[](long long i) const {
    return array[i];
}
//
//template <typename T>
//MyVector<T> MyVector<T>::filter(bool (*predicate)(const T&)) const {
//    MyVector<T> temp(_capacity);
//    for (long long i = 0; i < _size; i++)
//    {
//        if (predicate(_array[i])) {
//            temp.AddToEnd(_array[i]);
//        }
//    }
//    return temp;
//}
//
//template <typename T>
//template <typename V>
//V MyVector<T>::reduce(V(*op)(const T&, V), V startpoint) const {
//    for (long long i = 0; i < _size; i++)
//    {
//        startpoint = op(_array[i], startpoint);
//    }
//    return startpoint;
//}
//
//template <typename T>
//template <typename V>
//MyVector<V> MyVector<T>::map(V(*op)(const T&)) const{
//    MyVector<V> temp(_capacity);
//    for (long long i = 0; i < _size; i++)
//    {
//        temp.AddToEnd(op(_array[i]));
//    }
//    return temp;
//}
