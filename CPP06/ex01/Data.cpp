#include "Data.hpp"

Data::Data() : number(42), text("Lorem Ipsum Dolor Sit Amet")
{

}

Data::Data(int number, std::string text)
{
    this->number = number;
    this->text = text;
}

Data::Data(const Data & other)
{
    this->number = other.number;
    this->text = other.text;
}

Data &Data::operator=(const Data & other)
{
    if (&other != this)
    {
        this->number = other.number;
        this->text = other.text;
    }
    return *this;
}

Data::~Data()
{

}

int Data::getNumber() const
{
    return this->number;
}

std::string Data::getText() const
{
    return this->text;
}