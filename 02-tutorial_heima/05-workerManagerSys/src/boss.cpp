#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dId;

}

void Boss::show_info()
{
	cout << "Worker ID: " << this->m_ID
		<< " \tWorker name: " << this->m_Name
		<< " \tWorker department: " << this->get_dept_name()
		<< " \tJob: Rule the company" << endl;
}

string Boss::get_dept_name()
{
	return string("Boss");
}