#include <iostream>
using namespace std;

#include "workerManager.h"
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"


void test_worker()
{
    Worker * worker = NULL;

    worker = new Employee(1, "Zhangsan", 1);
    worker->show_info();
    delete worker;


    worker = new Manager(2, "Lisi", 2);
    worker->show_info();
    delete worker;
    
    worker = new Boss(0, "Wangwu", 0);
    worker->show_info();
    delete worker;
}



int main()
{
    WorkerManager wm;

    int choice = 0;

    while (true)
    {
        //展示菜单
        wm.show_menu();
        cout << "请输入您的选择:" << endl;
        cin >> choice;

        switch (choice)
        {
            case 0: //退出系统
                wm.exit_system();
                break;
            case 1: //添加职工
                wm.add_worker();
                break;
            case 2: //显示职工
                wm.show_worker();
                break;
            case 3: //删除职工
                wm.del_worker();
                break;
            case 4: //修改职工
                wm.mod_worker();
                break;
            case 5: //查找职工
                wm.find_worker();
                break;
            case 6: //排序职工
                wm.sort_worker();
                break;
            case 7: //清空文件
                wm.clean_file();
                break;
            default:
                break;
        }
    }

    return 0;
} 
