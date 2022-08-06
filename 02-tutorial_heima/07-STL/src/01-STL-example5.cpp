#include <iostream>

#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;


/*
#### 案例描述
* 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
* 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
* 随机给10名员工分配部门和工资
* 通过multimap进行信息的插入  key(部门编号) value(员工)
* 分部门显示员工信息
*/

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
    string m_Name;
    int m_Salary;
};


// 生成员工
void createWorker(vector<Worker>& v)
{
    string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "Employee";
        worker.m_Name +=nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;   // 10000 ~ 19999

        v.push_back(worker); 
    }
}

// 员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptID = rand() % 3; // 0 1 2

        // 将员工与部门绑定
        m.insert(make_pair(deptID, *it));
    }
}

// 根据分组显示员工
void showWorkerByGroup(multimap<int, Worker>& m)
{
    cout << "策划部门: " << endl;
    int count = m.count(CEHUA);
    int index = 0;
    for(multimap<int, Worker>::iterator pos = m.find(CEHUA);
        pos != m.end() && index < count; 
        pos++, index++)
    {
        cout << "Name: " << pos->second.m_Name 
             << " Salary: " << pos->second.m_Salary
             << " DepID: " << pos->first
             << endl;
    }

    cout << "美术部门: " << endl;
    count = m.count(MEISHU);
    index = 0;
    for(multimap<int, Worker>::iterator pos = m.find(MEISHU);
        pos != m.end() && index < count;
        pos++, index++)
    {
        cout << "Name: " << pos->second.m_Name
             << " Salary: " << pos->second.m_Salary
             << " DepID: " << pos->first
             << endl;
    }

    cout << "研发部门: " << endl;
    count = m.count(YANFA);
    index = 0;
    for(multimap<int, Worker>::iterator pos = m.find(YANFA);
        pos != m.end() && index < count;
        pos++, index++)
    {
        cout << "Name: " << pos->second.m_Name
             << " Salary: " << pos->second.m_Salary
             << " DepID: " << pos->first
             << endl;
    }

}


// 显示所有员工
void showWorker(multimap<int, Worker>& m)
{
    cout << "All employee: " << endl; 

    for(multimap<int, Worker>::iterator it = m.begin();
        it != m.end();
        it++)
    {
        cout << "Name: " << it->second.m_Name
             << "Salary: " << it->second.m_Salary
             << "DepID: " << it->first
             << endl;
    }

}

int main()
{
    // init rand
    srand((unsigned int)time(NULL));

    // 1 - generate employee
    vector<Worker> vWorker;
    createWorker(vWorker);

    // 2 - group
    multimap<int, Worker>mWorker;
    setGroup(vWorker, mWorker);

    // 3 - employee
    showWorkerByGroup(mWorker);

    // test
    showWorker(mWorker);

    return 0;

}