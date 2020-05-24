#include "workerManage.h"
#include "Employee.h"
#include <iostream>


using namespace std;

int main() {

    WorkerManage wm;
    int choice = 0;
    while(1) {
        wm.showMenu();
        cout << "请输入：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:  //退出程序
            wm.ExitSystem();
            break;
        case 1:  //增加员工
            wm.AddWorker();
            break;
        
        case 2:  //查找职工信息
        {
            cout << "输入要查找的员工id: " << endl;
            size_t id = 0;
            cin >> id;
            wm.Search(id);
            break;
        }

        case 3:  //显示所有职工信息
            cout << "共计工作人员" << wm.num_ << "人 " << endl; 
            wm.ShowWorker();
            break;

        case 4:  //删除离职职工信息
        {
            cout << "输入要删除的员工id: " << endl;
            size_t id = 0;
            cin >> id;
            wm.Delete(id);
            break;
        }

        case 5:  //修改职工信息
        {
            cout << "输入要查找的员工id: " << endl;
            size_t id = 0;
            cin >> id;
            wm.Modify(id);
            break;
        }

        case 6:  //清空所有文档
        {
            cout << "确定清空文档中所有信息? 确定: Y  不确定: N" << endl; 
            char c;
            cin >> c;
            if(c == 'Y')
                wm.ClearUp();
            break;
        }
        default:
            break;
        }
    }
    
    return 0;
}
