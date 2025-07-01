#pragma once

#include <iostream>

class Fixed
{
private:
	int	fixedNumber;
	static const int fractional = 8;
public:
	Fixed( void );
	Fixed( int value );
	Fixed( float value );
	Fixed(const Fixed& copy);

	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw);

	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);