#pragma once
#include <forward_declarations.h>
#include <employesloader.h>
#include <fstream>
#include <point.h>
#include <employee.h>
#include <map>

class EmployesLoader
{
public:
    static Employes FromTextFile(const std::string& file_name);
};
