#include <iostream>
using namespace std;

#include <vector>
#include <string>

/*
#### Vector存放自定义数据类型

学习目标：vector中存放自定义数据类型，并打印输出
*/

// 自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

public:
    string m_name;
    int m_age;
};


//存放数据
void test01()
{
    vector<Person> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

    v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name: " << (*it).m_name << " Age: " << (*it).m_age << endl;
    
    }
    
}


// 放对象指针
void test02()
{
    vector<Person*> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        Person * p = (*it);
        cout << "Name: " << p->m_name << " Age: " << (*it)->m_age << endl;
    }
}



int main()
{
    test01();
    test02();
    
    return 0;
}