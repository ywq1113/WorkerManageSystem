#include "Employee.h"

void Employee::ShowInfo()
{
    std::cout << "name = " << this->name_ << std::endl;
    std::cout  << "id = " << this->id_ << std::endl;
    std::cout << "department = " << this->department_ << std::endl;
}

void Employee::getLevel()
{
    std::cout << "level = " << this->level_ << std::endl;
}