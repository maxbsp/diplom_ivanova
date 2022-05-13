#pragma once
#include <point.h>
#include <matrix.h>
#include <employee.h>
#include <forward_declarations.h>
#include<unordered_map>

class DiagramBuilder
{

    using FrontsOfEmployes = std::unordered_map<size_t, WaveFront>;
public:

    static Matrix BuildDiagram(const Matrix& matrix, const std::vector<Employee>& employes)
    {
        Matrix diagramm = matrix;
        size_t filled_pixels = CountFilledPixels(matrix);
        size_t radius = 1;
        std::unordered_map<size_t, WaveFront> fronts = CreateFronts(diagramm, employes);
        while(FrontsLength(fronts) > 0)
        {
            for (const auto& employee : employes)
            {
                const auto& old_front = fronts[employee.Id()];
                fronts[employee.Id()] = ExtendWave(diagramm, employee, old_front, filled_pixels, radius);
            }
            ++radius;
        }
        return diagramm;
    }

private:
    static size_t FrontsLength(const FrontsOfEmployes& fronts)
    {
        size_t result = 0;
        for (const auto& [_,front] : fronts)
            result += front.size();
        return result;
    }

    /**
     * @brief Отмечает сотрудника на диаграмме и помещат его во фронт (так со всеми сотрудниками)
     * @param diagramm
     * @param employes
     * @return
     */
    static FrontsOfEmployes CreateFronts(Matrix& diagramm, const std::vector<Employee>& employes)
    {
        std::unordered_map<size_t, WaveFront> fronts;
        for (const auto& employee : employes)
        {
            fronts[employee.Id()].emplace_back(employee.Coordinates());
            DrawEmployee(diagramm, employee);
        }
        return fronts;
    }

    static void DrawEmployee(Matrix& diagramm, const Employee& employee)
    {
        diagramm[employee.Coordinates()] = Matrix::WALL;
    }

    static size_t CountFilledPixels(const Matrix& matrix)
    {
        size_t result = 0;
        for (size_t x = 0; x < matrix.Width(); ++x)
            for (size_t y = 0; y < matrix.Width(); ++y)
                if (!matrix.IsEmpty(Point{x, y}))
                    ++result;
        return result;
    }

    static WaveFront ExtendWave(Matrix& diagramm, const Employee& employee, const WaveFront& front, size_t& filled_pixels, size_t wave_radius)
    {
        WaveFront new_front;
        for (const auto& point : front)
        {
            for (const auto& neibourgh: point.Neighbours())
            {
                // Если вышли за границы экрана
                if (!diagramm.Includes(neibourgh))
                    continue;
                // Если ячейка уже заполнена
                if (!diagramm.IsEmpty(neibourgh))
                    continue;
                // Если не попадаем в радиус
                if (employee.Coordinates().DistanceTo(neibourgh) > wave_radius)
                    continue;
                diagramm[neibourgh] = employee.Id();
                ++filled_pixels;
                new_front.emplace_back(neibourgh);
            }
        }
        return new_front;
    }
};
