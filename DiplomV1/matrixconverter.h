#pragma once
#include <matrix.h>
#include <QImage>
#include <QRgb>
#include <QColor>
#include <vector>
#include <employee.h>
#include <forward_declarations.h>

class MatrixConverter
{
public:
    static Matrix FromImage(const QImage& image, int threshold)
    {
        Matrix result{static_cast<size_t>(image.width()), static_cast<size_t>(image.height())};
        for (int x = 0; x < image.width(); ++x)
            for (int y = 0; y < image.height(); ++y)
            {
                Point point{static_cast<size_t>(x), static_cast<size_t>(y)};
                if (qGray(image.pixel(x, y)) < threshold)
                    result[point] = Matrix::WALL;
                else
                    result[point] = Matrix::EMPTY;
            }
        return result;
    }

    static QImage ToImage(const Matrix& matrix, const Employes& employes)
    {
        QImage result{static_cast<int>(matrix.Width()), static_cast<int>(matrix.Height()), QImage::Format_RGB32};
        for (size_t x = 0; x < matrix.Width(); ++x)
            for (size_t y = 0; y < matrix.Height(); ++y)
            {
                Point point{x, y};
                if (matrix.IsEmpty(point))
                    result.setPixel(x, y, QColor{"white"}.rgb());
                else if (matrix.IsWall(point))
                    result.setPixel(x, y, QColor{"black"}.rgb());
                else
                    result.setPixel(x, y, employes[matrix[point]].Color());
            }
        return result;
    }
};
