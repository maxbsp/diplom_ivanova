#include "matrix.h"


Matrix::Matrix(size_t width, size_t height)
    : mWidth{width}, mHeight{height}, mData(width * height)
{
}

int Matrix::Value(const Point &p) const
{
    return mData[mWidth * p.Y() + p.X()];
}

int &Matrix::operator[](const Point &p)
{
    return mData[mWidth * p.Y() + p.X()];
}

bool Matrix::IsEmpty(const Point &p) const
{
    return Value(p) == EMPTY;
}

bool Matrix::IsWall(const Point &p) const
{
    return Value(p) == WALL;
}

bool Matrix::Includes(const Point &p) const
{
    return p.X() >= 0 && p.X() < mWidth && p.Y() >= 0 && p.Y() < mHeight;
}

size_t Matrix::Size() const
{
    return mData.size();
}

size_t Matrix::Width() const
{
    return mWidth;
}

size_t Matrix::Height() const
{
    return mHeight;
}

int Matrix::operator[](const Point &p) const
{
    return Value(p);
}
