/*
#### find_if
**功能描述：**
* 按条件查找元素
**函数原型：**

- `find_if(iterator beg, iterator end, _Pred);  `
  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  // beg 开始迭代器
  // end 结束迭代器
  // _Pred 函数或者谓词（返回bool类型的仿函数）

总结：find_if按条件查找使查找更加灵活，提供的仿函数可以改变不同的策略
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// 仿函数，大于5
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};


void test01()
{
    std::vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), GreaterFive());
    if(it == v.end())
    {
        std::cout << " Didn't find!" << std::endl;
    }
    else
    {
        std::cout << "Find num greater than 5: " << *it << std::endl;
    }
}


// Person 类
class Person {
public:
	Person(std::string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	std::string m_Name;
	int m_Age;
};


class AgeGreater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}

};


void test02()
{
    std::vector<Person> v;

    // 创建数据
    Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

    std::vector<Person>::iterator it = find_if(v.begin(), v.end(), AgeGreater20()); 
    if(it == v.end())
    {
        std::cout << "Didn't find!" << std::endl;
    }
    else
    {
        std::cout << "Find name: " << it->m_Name << " age: " << it->m_Age << std::endl;
    }
}


int main()
{
    test01();

    test02();

    return 0;
}
