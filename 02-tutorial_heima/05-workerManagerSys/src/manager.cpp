#include "manager.h"


/*
经理类**继承**职工抽象类，并重写父类中纯虚函数，和普通员工类似
*/


// constructor
Manager::Manager(int ID, string name, int dID)
{
    this->m_ID = ID;
    this->m_Name = name;
    this->m_DeptID = dID;
}

// show info
void Manager::show_info()
{
	cout << "Worker ID: " << this->m_ID
		<< " \tWorker name: " << this->m_Name
		<< " \tWorker department: " << this->get_dept_name()
		<< " \tJob: do the work from boss, and give work to employee" << endl;
}

// get department name
string Manager::get_dept_name()
{
    return string("Manager");
}