#pragma once
#include <cmath>
#include <vector>

class Point
{
public:
    Point(size_t x, size_t y);

    size_t X() const;

    size_t Y() const;

    /**
     * @brief Определение соседей,возвращает вектор соседник точек
     * @return
     */
    std::vector<Point> Neighbours() const;

    /**
     * @brief Находит расстояние между текущей точкой и интересующей
     * @param point
     * @return
     */
    double DistanceTo(const Point& point);
private:
    size_t mX = 0;
    size_t mY = 0;
};
