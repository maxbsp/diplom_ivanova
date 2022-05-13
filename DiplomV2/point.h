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
    size_t DistanceTo(const Point& point)
    {
        return sqrt((point.mX - mX) * (point.mX - mX) + (point.mY - mY) * (point.mY - mY));
    }
private:
    size_t mX = 0;
    size_t mY = 0;
};
