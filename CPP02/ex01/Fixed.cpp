#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed() : fixedNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value) : fixedNumber(value << 8)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedNumber = roundf(value * (1 << fractional));
}


Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedNumber = copy.getRawBits();
}
Fixed&  Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedNumber = other.getRawBits();
    }
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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