#pragma once
#include <point.h>
#include <vector>
#include <forward_declarations.h>

class Employee
{
public:
    Employee(size_t id, const Point& coordinates)
        :mId{id}, mCoordinates{coordinates}
    {

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

private:
    size_t mId = 0;
    Point mCoordinates;
    WaveFront mFront;
};
