#pragma once
#include <forward_declarations.h>
#include <employesloader.h>
#include <fstream>
#include <point.h>
#include <employee.h>

class EmployesLoader
{
public:
    static Employes FromTextFile(const std::string& file_name)
    {
        Employes result;
        std::ifstream file{file_name};
        size_t employes_count;
        file >> employes_count;
        for (size_t i = 0; i < employes_count; ++i)
        {
            size_t x, y;
            file >> x >> y;
            result.emplace_back(i, Point{x, y});
        }
        return result;
    }
};
