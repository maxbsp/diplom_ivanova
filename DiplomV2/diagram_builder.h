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

    static Matrix BuildDiagram(const Matrix& matrix, const std::vector<Employee>& employes, size_t time)
    {
        Matrix diagramm = matrix;
        size_t radius = 1;
        std::unordered_map<size_t, WaveFront> fronts = CreateFronts(diagramm, employes, time);
        while(FrontsLength(fronts) > 0)
        {
            for (const auto& employee : employes)
            {
                const auto& old_front = fronts[employee.Id()];
                fronts[employee.Id()] = ExtendWave(diagramm, employee, old_front, radius, time);
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
    static FrontsOfEmployes CreateFronts(Matrix& diagramm, const std::vector<Employee>& employes, size_t time)
    {
        std::unordered_map<size_t, WaveFront> fronts;
        for (const auto& employee : employes)
        {
            fronts[employee.Id()].emplace_back(employee.Coordinates(time));
            DrawEmployee(diagramm, employee, time);
        }
        return fronts;
    }

    static void DrawEmployee(Matrix& diagramm, const Employee& employee, size_t time)
    {
        diagramm[employee.Coordinates(time)] = Matrix::WALL;
    }

    static WaveFront ExtendWave(Matrix& diagramm, const Employee& employee, const WaveFront& front, size_t wave_radius, size_t time)
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
                if (employee.Coordinates(time).DistanceTo(neibourgh) > static_cast<float>(wave_radius))
                    continue;
                diagramm[neibourgh] = employee.Id();
                new_front.emplace_back(neibourgh);
            }
        }
        return new_front;
    }
};
