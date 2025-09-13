#pragma once

#include <stdexcept>

template <typename T>
class Array
{
private:
    T *data;
    unsigned int size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &other);
    Array<T> &operator=(const Array<T> &other);
    T &operator[](unsigned int n);
    const T &operator[](unsigned int n) const;
    unsigned int getSize() const;
    ~Array();
};

template <typename T>
Array<T>::Array() : data(0), size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : data(0), size(n)
{
    if (size > 0)
        data = new T[size]();
}

template <typename T>
Array<T>::Array(const Array<T> &other) : data(0), size(other.size)
{
    if (size > 0)
    {
        data = new T[size];
        for (unsigned int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this == &other)
        return *this;

    T *newData = 0;
    if (other.size > 0)
    {
        newData = new T[other.size];
        for (unsigned int i = 0; i < other.size; ++i)
            newData[i] = other.data[i];
    }

    delete[] data;
    data = newData;
    size = other.size;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return size;
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
    if (n >= size)
        throw std::out_of_range("Index out of bounds");
    return data[n];
}

template <typename T>
const T &Array<T>::operator[](unsigned int n) const
{
    if (n >= size)
        throw std::out_of_range("Index out of bounds");
    return data[n];
}
