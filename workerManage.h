/*
 * 管理类负责的内容：
 * 与用户沟通菜单界面
 * 对职工增删改查操作
 * 与文件读写交互
 */

#ifndef WORKERMANAGE_H
#define WORKERMANAGE_H

#include <iostream>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_container.hpp>
#include <fstream>

#define FILENAME "empFile.txt"

using namespace std;

class Worker;
class Employee;
typedef boost::ptr_list<Worker> SpList;

class WorkerManage
{
public:
    WorkerManage();

    ~WorkerManage() { }

    void showMenu();
    void InitEmp();

    void AddWorker();
    void AddWorker(int n);
    bool Delete(const size_t& id);
    bool Search(const size_t& id);
    void Modify(const size_t& id);
    void ShowWorker();
    void ClearUp();

    void PrintInfo(SpList::reverse_iterator it);
    void Save();
    bool ModifyCapcity(const int cap);
    void ExitSystem();

    size_t  GetEmpNum();
public:
    bool        fileIsEmpty_;
    size_t      num_;
    size_t      capcity_;
    SpList      workerlist_;
};

#endif