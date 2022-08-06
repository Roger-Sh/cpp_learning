#pragma once

#include <iostream>
#include <string>
using namespace std;


/*
创建职工抽象类 
职工的分类为：普通员工、经理、老板
将三种职工抽象到一个类（worker）中,利用多态管理不同职工种类
职工的属性为：职工编号、职工姓名、职工所在部门编号
职工的行为为：岗位职责信息描述，获取岗位名称
*/

// abstract class Worker
class Worker
{
public:

    // 纯虚函数抽象类
    // show info
    virtual void show_info() = 0;

    // get Department name
    virtual string get_dept_name() = 0;

    int m_ID;           // worker ID
    string m_Name;      // worker name
    int m_DeptID;       // worker department ID
};


