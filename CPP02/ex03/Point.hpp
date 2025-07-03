#pragma once

#include "Fixed.hpp"

class Point
{
private:
    Fixed x;
    Fixed y;
public:
    Point();
    Point(float x, float y);
    Point(Fixed& x, Fixed& y);
	Point& operator=(const Point& other);
    ~Point();
    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);