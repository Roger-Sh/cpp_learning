#pragma once

#include <iostream>
using namespace std;

#include "worker.h"

/*
### 创建普通员工类
普通员工类**继承**职工抽象类，并重写父类中纯虚函数
在头文件和源文件的文件夹下分别创建employee.h 和 employee.cpp文件
*/


// Class Employee from Worker
class Employee : public Worker
{
public:
    // constructor
    Employee(int ID, string name, int dID);

    // show info
    virtual void show_info();

    // get department name
    virtual string get_dept_name();

};