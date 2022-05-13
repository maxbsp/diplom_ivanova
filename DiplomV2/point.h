#pragma once
#include <cmath>
#include <vector>

class Point
{
public:
    Point(size_t x, size_t y)
        :mX{x}, mY{y}
    {
    }
    size_t X() const
    {
        return mX;
    }

    size_t Y() const
    {
        return mY;
    }

    /**
     * @brief Определение соседей,возвращает вектор соседник точек
     * @return
     */
    std::vector<Point> Neighbours() const
    {
        return {
            {mX - 1, mY - 1}, {mX, mY - 1}, {mX+1, mY-1},
            {mX - 1, mY},                 {mX+1, mY},
            {mX-1, mY+1},     {mX, mY+1},   {mX+1, mY+1}
        };
    }

    /**
     * @brief Находит расстояние между текущей точкой и интересующей
     * @param point
     * @return
     */
    double DistanceTo(const Point& point)
    {
        double x1 = mX;
        double x2 = point.mX;
        double y1 = mY;
        double y2 = point.mY;
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
private:
    size_t mX = 0;
    size_t mY = 0;
};
