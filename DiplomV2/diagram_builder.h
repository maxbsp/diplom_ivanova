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

    static Matrix BuildDiagram(const Matrix& matrix, const std::vector<Employee>& employes, size_t time);

private:
    static size_t FrontsLength(const FrontsOfEmployes& fronts);

    /**
     * @brief Отмечает сотрудника на диаграмме и помещат его во фронт (так со всеми сотрудниками)
     * @param diagramm
     * @param employes
     * @return
     */
    static FrontsOfEmployes CreateFronts(Matrix& diagramm, const std::vector<Employee>& employes, size_t time);

    static void DrawEmployee(Matrix& diagramm, const Employee& employee, size_t time);

    static WaveFront ExtendWave(Matrix& diagramm, const Employee& employee, const WaveFront& front, size_t wave_radius, size_t time);
};
