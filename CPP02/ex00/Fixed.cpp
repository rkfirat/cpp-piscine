#include "Fixed.hpp"


Fixed::Fixed() : fixedNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( Fixed& copy)
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
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedNumber;
}
void Fixed::setRawBits( int const raw )
{
    this->fixedNumber = raw;
    std::cout << "setRawBits member function called" << std::endl;
}