#pragma once

#include <iostream>
using namespace std;

#include "worker.h"

/*
### 创建老板类
老板类**继承**职工抽象类，并重写父类中纯虚函数，和普通员工类似
在头文件和源文件的文件夹下分别创建boss.h 和 boss.cpp文件
*/

// class Boss from Worker
class Boss : public Worker
{
public:
    
    // constructor
    Boss(int ID, string name, int dID);

    // show info
    virtual void show_info();

    // get department name
    virtual string get_dept_name();

};
