#include "workerManage.h"
#include "Employee.h"
#include "Worker.h"
#include <algorithm>
#include <functional>

WorkerManage::WorkerManage()
{
        ifstream  ifs;
        ifs.open(FILENAME, ios::in);
        if(!ifs.is_open()) {
            cout << "文件不存在" << endl;
            num_ = 0;
            this->fileIsEmpty_ = true;
            ifs.close();
            return;
        }
        char c;
        ifs >> c;
        if(ifs.eof()) {
            cout << "文件为空" << endl;
            this->num_ = 0;
            this->fileIsEmpty_ = true;
            ifs.close();
            return;
        }
        //size_t num = this->GetEmpNum();
        this->InitEmp();
        cout << "职工人数为：" << num_ << endl;
        this->capcity_ = 1000;
        this->fileIsEmpty_ = false;
}

void WorkerManage::InitEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    this->num_ = 0;
    string name("");
    size_t id(0);
    string department("");
    string level("");
    while(ifs >> id && ifs >> name && ifs >> department && ifs >> level) 
    {
        this->workerlist_.push_front(new Employee(name,id,department,level));
        this->num_++;
    }
    ifs.close();
}

void WorkerManage::showMenu()
{
    cout << "***************************************" << endl;
    cout << "*******  欢迎使用职工管理系统!  *******" << endl;
    cout << "*********  0.退出管理程序  **********" << endl;
    cout << "*********  1.增加职工信息  **********" << endl;
    cout << "*********  2.查找职工信息  **********" << endl;
    cout << "*********  3.显示所有职工  **********" << endl;
    cout << "*********  4.删除职工信息  **********" << endl;
    cout << "*********  5.修改职工信息  **********" << endl;
    cout << "*********  6.清空所有文档  **********" << endl;
    cout << endl;
}

void WorkerManage::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkerManage::AddWorker() 
{
    if(this->num_ == this->capcity_) {
        cout << "员工人数已达到上限，无法添加员工" << endl;
        return;
    }
    ofstream ofs;
    ofs.open(FILENAME, std::ios::ate | std::ios::out);
    ofs.close();

    size_t id;
    string name;
    string department;
    string level;

    cout << "输入员工姓名：" << endl;
    cin >> name;
    cout << "输入员工ID：" << endl;
    cin >> id;
    cout << "输入员工部门：" << endl;
    cin >> department;
    cout << "输入员工级别：" << endl;
    cin >> level;

    SpList::iterator it = this->workerlist_.begin();
    this->workerlist_.push_back(new Employee(name, id, department, level));
    this->num_++;
    this->fileIsEmpty_ = false;
    this->Save();
    
    cout << "成功添加新员工" << endl;
}

void WorkerManage::AddWorker(int n)
{
    if(n <= 0) {
        cout << "无效的输入" << endl;
        return;
    }
    else {
        if(this->num_ + n > capcity_)
        {
            int tmp = capcity_ - num_;
            cout << "无法添加" << n << "个人数," << "容量剩余" << tmp << "数目" << endl;
            return;
        }
        for(int i = 0; i < n; ++i) {
            size_t id;
            string name;
            string department;
            string level;

            cout << "输入员工姓名：" << endl;
            cin >> name;
            cout << "输入员工ID：" << endl;
            cin >> id;
            cout << "输入员工部门：" << endl;
            cin >> department;
            cout << "输入员工级别：" << endl;
            cin >> level;
            //boost::share_ptr<Worker> new_Worker(new Employee(name, id, department, level));
            this->workerlist_.push_front(new Employee(name, id, department, level));

        }
        this->num_  += n;
        cout << "Complete !" << endl;
        this->Save();
    }
}

bool WorkerManage::Search(const size_t& id)
{
    SpList::reverse_iterator it = this->workerlist_.rbegin();
    for(; it != workerlist_.rend(); )
    {
        if(it->id_ == id) {
            this->PrintInfo(it);
            return true;
        }
        ++it;
    }
    cout << "Don't find this employee, check your input" << endl;
    return false;
}

bool WorkerManage::Delete(const size_t& id) 
{
    size_t tmp = this->num_;
    SpList::iterator s = workerlist_.begin();
    for(; s != workerlist_.end();) 
    {
        if(s->id_ == id)
        {
            workerlist_.erase(s);
            this->num_--;
            this->Save();
            break;
        }
        ++s;
    }
    if(this->num_ != tmp)
    {
        cout << "Don't find this Employee" << endl;
        return false;
    }
    this->Save();
    return true; 
}

void WorkerManage::Modify(const size_t& id)
{

}

void WorkerManage::ShowWorker()
{
    workerlist_.clear();
    this->InitEmp();
    SpList::reverse_iterator it = workerlist_.rbegin();
    for( ;it != workerlist_.rend(); ) 
    {
        this->PrintInfo(it);
        ++it;
    }
}

void WorkerManage::ClearUp()
{
    ofstream ofs;
    ofs.open(FILENAME, std::ios::ate | std::ios::out);
    ofs.close();
    this->workerlist_.clear();
    this->num_ = 0;
    this->fileIsEmpty_ = true;
    cout << "Complete!" << endl;
}

void WorkerManage::PrintInfo(SpList::reverse_iterator it)
{
    cout << "员工姓名：" << it->name_ << endl;
    cout << "员工id：" << it->id_ << endl;
    cout << "员工部门：" << it->department_ << endl;
    cout << "员工职级：" << it->level_ << endl;
}

void WorkerManage::Save()
{
    ofstream ofs;
    ofs.open(FILENAME, std::ios::app | std::ios::out);  //进入写操作定位到文件的末尾

    SpList::iterator it = workerlist_.begin();

    for(; it != workerlist_.end(); ) 
    {
        ofs << it->id_ << " " <<
               it->name_ << " " <<
               it->department_ << " " <<
               it->level_ << " " << endl;
        it++;
    }
    cout << "Complete! " << endl;
    ofs.close();
}

size_t WorkerManage::GetEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    size_t num = 0;

    size_t id(0);
    string name("");
    string department("");
    string level("");
    while(ifs >> name && ifs >> id && ifs >> department && ifs >> level)
    {
        num++;
    }
    return num;
    ifs.close();
}

bool WorkerManage::ModifyCapcity(const int cap)
{
    if(this->capcity_ >= cap)
    {
        cout << "Don't reduce the capcity" << endl;
        return false;
    }
    this->capcity_ = cap;
    cout << "Complete !" << endl;
    return true;
}
