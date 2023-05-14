#include "MyVector.h"

template class MyVector<int>;

template <typename T>
MyVector<T>::MyVector(size_t cappacity) {
    _cappacity = cappacity;
    _size = 0;
    _array = new T[_cappacity];
}

template <typename T>
void MyVector<T>::copy(const MyVector& other)
{
    _array = new T[other._cappacity];
    for (size_t i = 0; i < other._size; i++)
    {
        _array[i] = other._array[i];
    }
    _size = other._size;
    _cappacity = other._cappacity;
}

template <typename T>
void MyVector<T>::erase() {
    delete[] _array;
}

template <typename T>
MyVector<T>::MyVector(const T* array, const size_t size, const size_t cappacity)
{
    _size = size;
    _cappacity = cappacity;
    _array = new T[cappacity];
    for (size_t i = 0; i < size; i++)
    {
        _array[i] = array[i];
    }

}

template <typename T>
MyVector<T>::MyVector(const MyVector &other)
{
    copy(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator = (const MyVector<T>& other) {
    if (this != &other) {
        erase();
        copy(other);
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    erase();
}

template <typename T>
void MyVector<T>::AddToEnd(const T& arg)
{
    if (_size == _cappacity) {
        resize();
    }
    _array[_size++] = arg;
}

template <typename T>
void MyVector<T>::AddToPosition(size_t position, const T& arg) {
    if (position >= _cappacity) {
        return;
    }
    _array[position] = arg;
}

template <typename T>
void MyVector<T>::RemoveAtPosition(size_t position) {
    if (position >= _size) {
        return;
    }
    for (size_t i = position+1; i < _size; i++)
    {
        _array[i - 1] = _array[i];
    }
    _size -= 1;
}

template <typename T>
size_t MyVector<T>::Size() const{
    return _size;
}

template <typename T>
void MyVector<T>::EndToStart() {
    T* temp = new T[_cappacity];
    for (size_t i = 0; i < _size; i++)
    {
        temp[i] = _array[_size - i - 1];
    }
    delete[] _array;
    _array = temp;
}

template <typename T>
void MyVector<T>::resize() {
    T* temp = new T[_cappacity * 2];
    for (size_t i = 0; i < _size; i++)
    {
        temp[i] = _array[i];
    }
    _cappacity = _cappacity * 2;
    delete[] _array;
    _array = temp;
}
template <typename T>
T& MyVector<T>::operator[](size_t i) {
    return _array[i];
}

template <typename T>
T MyVector<T>::operator[](size_t i) const {
    return _array[i];
}

template <typename T>
MyVector<T> MyVector<T>::filter(bool (*predicate)(const T&)) const {
    MyVector<T> temp(_cappacity);
    for (size_t i = 0; i < _size; i++)
    {
        if (predicate(_array[i])) {
            temp.AddToEnd(_array[i]);
        }
    }
    return temp;
}

template <typename T>
template <typename V>
V MyVector<T>::reduce(V(*op)(const T&, V), V startpoint) const {
    for (size_t i = 0; i < _size; i++)
    {
        startpoint = op(_array[i], startpoint);
    }
    return startpoint;
}

template <typename T>
template <typename V>
MyVector<V> MyVector<T>::map(V(*op)(const T&)) const{
    MyVector<V> temp(_cappacity);
    for (size_t i = 0; i < _size; i++)
    {
        temp.AddToEnd(op(_array[i]));
    }
    return temp;
}
