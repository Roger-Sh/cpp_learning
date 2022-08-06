#pragma once

#include <iostream>
using namespace std;

#include "worker.h"

/*
经理类**继承**职工抽象类，并重写父类中纯虚函数，和普通员工类似
*/


// class Manager from Worker
class Manager : public Worker
{
public:

    // constructor
    Manager(int ID, string name, int dID);

    // show info
    virtual void show_info();

    // get department name
    virtual string get_dept_name();

};