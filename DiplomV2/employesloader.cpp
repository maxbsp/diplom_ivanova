#include "employesloader.h"

Employes EmployesLoader::FromTextFile(const std::string &file_name)
{
    std::ifstream file{file_name};
    size_t employes_count;
    file >> employes_count;
    std::map<size_t, Employee> employes;
    for (size_t i = 0; i < employes_count; ++i)
    {
        size_t id, time, x, y;
        file >> id >> time >> x >> y;
        auto& employee = employes[id];
        employee.SetId(id);
        employee.AddPoint(time, Point{x, y});
    }
    Employes result;
    for (const auto& [_, employee] : employes)
        result.emplace_back(employee);
    return result;
}
