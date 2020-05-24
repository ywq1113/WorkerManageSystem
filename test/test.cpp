#include "workerManage.h"
#include "Worker.h"
#include "Employee.h"
#include <memory>

using namespace std;

int main() 
{
    int id = 1;
    shared_ptr<Worker> w(new Employee("张三", id, "研发", "初级"));
    w->ShowInfo();
    w->getLevel();
}
