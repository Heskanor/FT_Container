// Self implementation of
// the Vector Class in C++
#pragma once
#include <iostream>
#include <memory>
#include <iterator>
using namespace std;
//vector implementation

namespace ft
{
//SFINEA
//Substitution failure is not an error


template <typename T>
class vectorClass
{
    private:
        T *arr;
        int size;
        int capacity;
        void resize(int newCapacity);
    public:
        vectorClass();
        vectorClass(int capacity);
        vectorClass(const vectorClass<T> &v);
        ~vectorClass();
        int getSize();
        int getCapacity();
        void push_back(T element);
        void pop_back();
        T& operator[](int index);
        vectorClass<T>& operator=(const vectorClass<T> &v);
        void print();
};
template <typename T>
vectorClass<T>::vectorClass()
{
    arr = NULL;
    size = 0;
    capacity = 0;
}
template <typename T>
vectorClass<T>::vectorClass(int capacity)
{
    arr = new T[capacity];
    size = 0;
    this->capacity = capacity;
}
template <typename T>
vectorClass<T>::vectorClass(const vectorClass<T> &v)
{
    arr = new T[v.capacity];
    size = v.size;
    capacity = v.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = v.arr[i];
}
template <typename T>
vectorClass<T>::~vectorClass()
{
    delete[] arr;
}
template <typename T>
int vectorClass<T>::getSize()
{
    return size;
}
template <typename T>
int vectorClass<T>::getCapacity()
{
    return capacity;
}
template <typename T>
void vectorClass<T>::resize(int newCapacity)
{
    T *newArr = new T[newCapacity];
    for(int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
template <typename T>
void vectorClass<T>::push_back(T element)
{
    if(size == capacity)
        resize(capacity * 2);
    arr[size++] = element;
}
template <typename T>
void vectorClass<T>::pop_back()
{
    if(size == 0)
        return;
    size--;
    if(size <= capacity / 4)
        resize(capacity / 2);
}
template <typename T>
T& vectorClass<T>::operator[](int index)
{
    return arr[index];
}
template <typename T>
vectorClass<T>& vectorClass<T>::operator=(const vectorClass<T> &v)
{
    if(this == &v)
        return *this;
    delete[] arr;
    arr = new T[v.capacity];
    size = v.size;
    capacity = v.capacity;
    for(int i = 0; i < size; i++)
        arr[i] = v.arr[i];
    return *this;
}
template <typename T>
void vectorClass<T>::print()
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//end of vector implementation
//type traits for the vector class


}
