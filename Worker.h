#pragma once
#include <iostream>
#include <string>

using namespace std;


// 员工抽象基类
class Worker {
public:

    Worker() { };

    virtual ~Worker() { };

    virtual void ShowInfo() = 0;

    virtual void getLevel() = 0;

public:
    string      name_;
    string      level_;
    string      department_;
    size_t      id_;
};
