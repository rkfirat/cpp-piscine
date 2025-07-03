#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed() : fixedNumber(0)
{
    
}

Fixed::Fixed(int value) : fixedNumber(value << 8)
{

}

Fixed::Fixed(float value)
{
    this->fixedNumber = roundf(value * (1 << fractional));
}


Fixed::Fixed(const Fixed& copy)
{
    this->fixedNumber = copy.getRawBits();
}
Fixed&  Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->fixedNumber = other.getRawBits();
    }
    return *this;
}
Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
    return (float)this->fixedNumber / (1 << fractional);
}

int Fixed::toInt(void) const
{
    return (int)this->fixedNumber >> fractional;
}

int Fixed::getRawBits( void ) const
{
     return this->fixedNumber;
}
void Fixed::setRawBits( int const raw )
{
    this->fixedNumber = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other.toFloat() == 0)
    {
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    ++this->fixedNumber;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixedNumber++;
    return temp;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->toFloat() != other.toFloat());
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}
