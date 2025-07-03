#include "Point.hpp"

static float area(Point const p1, Point const p2, Point const p3)
{
    float result = (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
                  + p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
                  + p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f;

    return (result < 0) ? -result : result;
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float area_abc = area(a, b, c);
    float area_pab = area(point, a, b);
    float area_pbc = area(point, b, c);
    float area_pca = area(point, c, a);

    if (area_pab == 0 || area_pbc == 0 || area_pca == 0)
        return false;

    return (area_abc == area_pab + area_pbc + area_pca);
}
