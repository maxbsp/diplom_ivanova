#pragma once
#include<vector>
#include<point.h>

class Matrix
{
public:
    static constexpr int EMPTY = -2;    //-2 - не закрашенная область
    static constexpr int WALL = -1;     //-1 - препятствие на плане
    Matrix(size_t width, size_t height)
        : mWidth{width}, mHeight{height}, mData(width * height)
    {
    }

    int Value(const Point& p) const
    {
        return mData[mWidth * p.Y() + p.X()];
    }

    int operator[](const Point& p) const
    {
        return Value(p);
    }

    int& operator[](const Point& p)
    {
        return mData[mWidth * p.Y() + p.X()];
    }

    bool IsEmpty(const Point& p) const
    {
        return Value(p) == EMPTY;
    }

    bool IsWall(const Point& p) const
    {
        return Value(p) == WALL;
    }

    bool Includes(const Point& p) const
    {
        return p.X() >= 0 && p.X() < mWidth && p.Y() >= 0 && p.Y() < mHeight;
    }

    size_t Size() const
    {
        return mData.size();
    }

    size_t Width() const
    {
        return mWidth;
    }

    size_t Height() const
    {
        return mWidth;
    }

private:
    size_t mWidth = 0;
    size_t mHeight = 0;
    std::vector<int> mData;
};
