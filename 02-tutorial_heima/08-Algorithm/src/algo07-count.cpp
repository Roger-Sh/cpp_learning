/*
#### count
**功能描述：**
* 统计元素个数

**函数原型：**
- `count(iterator beg, iterator end, value);  `
  // 统计元素出现次数
  // beg 开始迭代器
  // end 结束迭代器
  // value 统计的元素

**总结：** 统计自定义数据类型时候，需要配合重载 `operator==`


#### count_if
**功能描述：**
* 按条件统计元素个数
**函数原型：**
- `count_if(iterator beg, iterator end, _Pred);  `
  // 按条件统计元素出现次数
  // beg 开始迭代器
  // end 结束迭代器
  // _Pred 谓词

**总结：**按值统计用count，按条件统计用count_if

*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>




class Person
{
public:
    std::string m_name;
    int m_age;

public:
    Person(std::string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    // 判断年龄相等
    bool operator==(const Person &p)
    {
        if(this->m_age == p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


// 普通数据的count
void test01()
{
    std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = std::count(v.begin(), v.end(), 4);

	std::cout << "4的个数为： " << num << std::endl;

}


// 自定义数据的count
void test02()
{
    // 准备数据
    std::vector<Person> v;
    Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);


    // count，自定义数据需要配合重载operator==
    Person p("诸葛亮", 35);
    int num = std::count(v.begin(), v.end(), p);
    std::cout << "num = " << num << std::endl;
}


// 仿函数
class Greater4
{
public:
    bool operator()(int val)
    {
        return val >= 4;
    }
};


// 谓词
class AgeLess35
{
public:
    bool operator()(const Person &p)
    {
        return p.m_age < 35;
    }
};


// count_if 内置数据类型
void test03()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = std::count_if(v.begin(), v.end(), Greater4());

	std::cout << "大于4的个数为： " << num << std::endl;
}


// count_if, 自定义数据类型
void test04()
{
    // 准备数据
	std::vector<Person> v;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

    // count_if, 自定义数据
    int num = count_if(v.begin(), v.end(), AgeLess35());
    std::cout << "小于35岁的个数：" << num << std::endl;
}



int main()
{
    test01();

    test02();

    test03();

    test04();

    return 0;
}