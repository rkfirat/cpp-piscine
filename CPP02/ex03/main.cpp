#include <iostream>
#include "Point.hpp"



int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    Point pointInside(5, 5);
    Point pointOutside(8, 9);
    Point pointOnEdge(5, 0);

    std::cout << "Test 1: Point is inside the triangle\n";
    std::cout << "Result: " << (bsp(a, b, c, pointInside) ? "Yes" : "No") << std::endl;

    std::cout << "Test 2: Point is outside the triangle\n";
    std::cout << "Result: " << (bsp(a, b, c, pointOutside) ? "Yes" : "No") << std::endl;

    std::cout << "Test 3: Point is on the edge of the triangle\n";
    std::cout << "Result: " << (bsp(a, b, c, pointOnEdge) ? "Yes" : "No") << std::endl;

    return 0;
}
