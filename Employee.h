#pragma once
#include "Worker.h"
#include <iostream>
#include <string>

class Employee : public Worker
{
public:
    Employee(const std::string& name, const size_t& id, const std::string& department, const std::string& level) 
    { 
        this->name_ = name;
        this->id_ = id;
        this->department_ = department;
        this->level_ = level;
    }

    ~Employee() { }

    virtual void ShowInfo();
    virtual void getLevel();
};