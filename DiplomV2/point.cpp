#include "point.h"

Point::Point(size_t x, size_t y)
    :mX{x}, mY{y}
{
}

size_t Point::X() const
{
    return mX;
}

size_t Point::Y() const
{
    return mY;
}

std::vector<Point> Point::Neighbours() const
{
    return {
        {mX - 1, mY - 1}, {mX, mY - 1}, {mX+1, mY-1},
        {mX - 1, mY},                 {mX+1, mY},
        {mX-1, mY+1},     {mX, mY+1},   {mX+1, mY+1}
    };
}

double Point::DistanceTo(const Point &point)
{
    double x1 = mX;
    double x2 = point.mX;
    double y1 = mY;
    double y2 = point.mY;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
