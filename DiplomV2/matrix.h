#pragma once
#include<vector>
#include<point.h>

class Matrix
{
public:
    static constexpr int EMPTY = -2;    //-2 - не закрашенная область
    static constexpr int WALL = -1;     //-1 - препятствие на плане
    Matrix(size_t width, size_t height);

    int Value(const Point& p) const;

    int operator[](const Point& p) const;

    int& operator[](const Point& p);

    bool IsEmpty(const Point& p) const;

    bool IsWall(const Point& p) const;

    bool Includes(const Point& p) const;

    size_t Size() const;

    size_t Width() const;

    size_t Height() const;

private:
    size_t mWidth = 0;
    size_t mHeight = 0;
    std::vector<int> mData;
};
