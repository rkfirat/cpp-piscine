#pragma once

#include <vector>

class Span
{
private:
    std::vector<int> numbers;
    unsigned int size;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    long longestSpan();
    long shortestSpan();
};
