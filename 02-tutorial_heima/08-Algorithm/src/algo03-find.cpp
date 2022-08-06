/*
### 常用查找算法
学习目标：
- 掌握常用的查找算法

**算法简介：**
- `find`                     //查找元素
- `find_if`               //按条件查找元素
- `adjacent_find`    //查找相邻重复元素
- `binary_search`    //二分查找法
- `count`                   //统计元素个数
- `count_if`             //按条件统计元素个数


#### find
**功能描述：**
* 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

**函数原型：**
- `find(iterator beg, iterator end, value);  `
  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  // beg 开始迭代器
  // end 结束迭代器
  // value 查找的元素


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Person 类
class Person
{
public:
    std::string m_Name;
    int m_Age;

public:
    Person(std::string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    // override == 
    bool operator==(const Person& p)
    {
        if (this->m_Name == p.m_Name && 
            this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
};


void test01()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    // 查找容器中是否有5这个元素
    std::vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it == v.end())
    {
        std::cout << "Didn't find" << std::endl;
    }
    else
    {
        std::cout << "Find: " << *it << std::endl; 
    }
}



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

    // 在v中寻找p2
    std::vector<Person>::iterator it = find(v.begin(), v.end(), p2);

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
