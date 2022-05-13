#pragma once
#include <point.h>
#include <vector>
#include <forward_declarations.h>
#include <QRgb>
#include <QRandomGenerator>

class Employee
{
public:
    Employee(size_t id, const Point& coordinates)
        :mId{id}, mCoordinates{coordinates}
    {
        mColor = qRgb(QRandomGenerator::global()->generate(), QRandomGenerator::global()->generate(), QRandomGenerator::global()->generate());
    }
    // координаты сотрудника
    Point Coordinates() const
    {
        return mCoordinates;
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
    Point mCoordinates;
    WaveFront mFront;
    QRgb mColor;
};
