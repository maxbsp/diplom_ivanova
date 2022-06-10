#pragma once
#include <matrix.h>
#include <QImage>
#include <QRgb>
#include <QColor>
#include <vector>
#include <employee.h>
#include <forward_declarations.h>
#include <QPainter>

class MatrixConverter
{
public:
    static Matrix FromImage(const QImage& image, int threshold);

    static QImage ToImage(const Matrix& matrix, const Employes& employes, size_t time);
};
