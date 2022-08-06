#include "employee.h"


/*
### 创建普通员工类
普通员工类**继承**职工抽象类，并重写父类中纯虚函数
在头文件和源文件的文件夹下分别创建employee.h 和 employee.cpp文件
*/


// constructor
Employee::Employee(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}

// show info
void Employee::show_info()
{
	cout << "Worker ID: " << this->m_ID
		<< " \tWorker name: " << this->m_Name
		<< " \tWorker department: " << this->get_dept_name()
		<< " \tJob: do the work from manager" << endl;
}

// get department name
string Employee::get_dept_name()
{
	return string("Employee");
}
