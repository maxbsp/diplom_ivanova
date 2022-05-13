#pragma once
#include <point.h>
#include <vector>
#include <forward_declarations.h>
#include <QRgb>
#include <QRandomGenerator>
#include <map>

class Employee
{
public:
    Employee()
    {
        mColor = qRgb(QRandomGenerator::global()->generate(), QRandomGenerator::global()->generate(), QRandomGenerator::global()->generate());
    }
    // координаты сотрудника
    Point Coordinates(size_t current_time) const
    {
        size_t prev_time = 0;
        Point prev_point{0, 0};
        if (mCoordinates.size() == 1)
            return mCoordinates.at(0);
        for (const auto& [next_time, next_point] : mCoordinates)
        {
            if (current_time > prev_time && current_time < next_time)
            {
                size_t x = Approximate(current_time, prev_time, next_time, prev_point.X(), next_point.X());
                size_t y = Approximate(current_time, prev_time, next_time, prev_point.Y(), next_point.Y());
                return Point{x, y};
            }
            prev_time = next_time;
            prev_point = next_point;
        }
        return prev_point;
    }

    void AddPoint(size_t time, const Point& point)
    {
        mCoordinates.emplace(time, point);
    }

    void SetId(size_t id)
    {
        mId = id;
    }

    size_t Id() const
    {
        return mId;
    }
    // фронт волны для текущего сотрудника
    WaveFront Front() const
    {
        return mFront;
    }

    QRgb Color() const
    {
        return mColor;
    }

private:
    size_t mId = 0;
    std::map<size_t, Point> mCoordinates;
    WaveFront mFront;
    QRgb mColor;

    static float Approximate(float x_medium, float x1, float x2, float y1, float y2)
    {
        /*
         * dx1 -> dy1
         * dx2 -> dy2 (?)
         */
        float dx1 = x2 - x1;
        float dx2 = x_medium - x1;
        float dy1 = y2 - y1;
        float dy2 = dx2 * dy1 / dx1;
        return y1 + dy2;
    }
};
