#include "Point.hpp"

Point::Point()
{
    this->x = Fixed(0);
    this->y = Fixed(0);
}

Point::Point(float x, float y)
{
    this->x = Fixed(x);
    this->y = Fixed(y);
}

Point::Point(Fixed& x, Fixed& y)
{

    this->x = x;
    this->y = y;
}

Point& Point::operator=(const Point& other)
{
    if (this != &other)
    {
        this->x = other.getX();
        this->y = other.getY();
    }
    return *this;
}

Point::~Point()
{

}

Fixed Point::getX() const
{
    return this->x;
}
Fixed Point::getY() const
{
    return this->y;
}