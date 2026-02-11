#include "Span.hpp"

Span::Span()
{

}


Span::Span(unsigned int N)
{
    this->size = N;
}


Span::Span(const Span &other)
{
    this->size = other.size;
    this->numbers = other.numbers;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->size = other.size;
        this->numbers = other.numbers;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (size == this->numbers.size())
    {
        throw std::runtime_error("span is full");
    }
    this->numbers.push_back(number);
}

long Span::longestSpan()
{
    if (this->numbers.size() < 2)
        throw std::runtime_error("No span can be found.");
    return (*std::max_element(this->numbers.begin(), this->numbers.end()) - *std::min_element(this->numbers.begin(), this->numbers.end()));
}

long Span::shortestSpan()
{
    if (this->numbers.size() < 2)
        throw std::runtime_error("No span can be found.");
    std::vector<int> copiedVector = numbers;
    std::sort(copiedVector.begin(), copiedVector.end());
    long span = std::numeric_limits<long>::max();
    for (size_t i = 0; i < copiedVector.size() - 1; ++i)
    {
        long diff = static_cast<long>(copiedVector[i + 1]) - copiedVector[i];
        if (diff < span)
        {
            span = diff;
        }
    }
    return (span);
}