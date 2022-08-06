#include <iostream>
using namespace std;

#include <string>

/*
**局限性：**
* 模板的通用性并不是万能的，比如
    1 - 如果传入的a和b的类型是数组，那么无法进行赋值操作
    2 - 如果传入类这种自定义数据类型，无法进行运算符操作

C++为了解决这种问题，提供模板的重载，可以为这些**特定的类型**提供**具体化的模板**

总结：

* 利用具体化的模板，可以解决自定义类型的通用化
* 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板


*/


class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

public:
    string m_name;
    int m_age;

};


// 普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//具体化函数模板，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<> bool myCompare(Person& p1, Person& p2)
{
    if ( p1.m_name  == p2.m_name && p1.m_age == p2.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void test01()
{
	int a = 10;
	int b = 20;
	//内置数据类型可以直接使用通用的函数模板
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main()
{
    test01();

    test02();

    return 0;
}