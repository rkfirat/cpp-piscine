#pragma once

#include <iostream>

class Fixed
{
private:
	int	fixedNumber;
	static const int fractional = 8;
public:
	Fixed();
	Fixed( Fixed& copy);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw);
};
