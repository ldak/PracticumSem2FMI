#include "MyVector.h"

template class MyVector<int>;

template <typename T>
MyVector<T>::MyVector(size_t capacity) {
    _capacity = capacity;
    _size = 0;
    _array = new T[_capacity];
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector<T> &other)
{
    _array = new T[other._capacity];
    for (size_t i = 0; i < other._size; i++)
    {
        _array[i] = other._array[i];
    }
    _size = other._size;
    _capacity = other._capacity;
}

template <typename T>
void MyVector<T>::free() {
    delete[] _array;
}

template <typename T>
MyVector<T>::MyVector(const T* array, const size_t size, const size_t capacity)
{
    _size = size;
    _capacity = capacity;
    _array = new T[capacity];
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
void MyVector<T>::add(const T& arg)
{
    if (_size == _capacity) {
        resize();
    }
    _array[_size++] = arg;
}

template <typename T>
void MyVector<T>::add(size_t position, const T& arg) {
    if (position >= _capacity) {
        return;
    }
    _array[position] = arg;
}

template <typename T>
void MyVector<T>::remove(size_t position) {
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
void MyVector<T>::reverse() {
    T* temp = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
    {
        temp[i] = _array[_size - i - 1];
    }
    delete[] _array;
    _array = temp;
}

template <typename T>
void MyVector<T>::resize() {
    T* temp = new T[_capacity * 2];
    for (size_t i = 0; i < _size; i++)
    {
        temp[i] = _array[i];
    }
    _capacity = _capacity * 2;
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
    MyVector<T> temp(_capacity);
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
    MyVector<V> temp(_capacity);
    for (size_t i = 0; i < _size; i++)
    {
        temp.AddToEnd(op(_array[i]));
    }
    return temp;
}
