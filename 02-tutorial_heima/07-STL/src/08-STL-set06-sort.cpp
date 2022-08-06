#include <iostream>
#include <set>

using namespace std;

/*
#### set容器排序
学习目标：
* set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：
* 利用仿函数，可以改变排序规则
* 对于自定义数据类型，set必须指定排序规则才可以插入数据

*/


class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

class comparePerson
{
public:
    bool operator()(const Person& p1, const Person& p2)
    {
        // sort by age, descent
        return p1.m_age > p2.m_age;
    }
};


// **示例一**   set存放内置数据类型
void test01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

    // 默认set从小到大排序
    for(set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 使用自定义的排序方式
    // define sort rule
    set<int, MyCompare> s2;
    s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}


// **示例二** set存放自定义数据类型
void test02()
{
    set<Person, comparePerson> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_name << " 年龄： " << it->m_age << endl;
	}
}


int main()
{
    test01();

    return 0;

}