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
    Point Coordinates(size_t current_time) const;

    void AddPoint(size_t time, const Point& point);

    void SetId(size_t id);

    size_t Id() const;
    // фронт волны для текущего сотрудника
    WaveFront Front() const;

    QRgb Color() const;

private:
    size_t mId = 0;
    std::map<size_t, Point> mCoordinates;
    WaveFront mFront;
    QRgb mColor;

    static float Approximate(float x_medium, float x1, float x2, float y1, float y2);
};
