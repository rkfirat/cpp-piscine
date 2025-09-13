#pragma once

#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t size, F f)
{
    for (size_t i = 0; i < size; i++)
    {
        f(array[i]);
    }
}

template <typename T, typename F>
void iter(const T* array, size_t size, F f)
{
    for (size_t i = 0; i < size; i++)
    {
        f(array[i]);
    }
}