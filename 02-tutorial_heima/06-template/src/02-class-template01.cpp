#include <iostream>
using namespace std;


/*

类模板作用：

* 建立一个通用类，类中的成员 数据类型可以不具体制定，用一个**虚拟的类型**来代表。

template  ---  声明创建模板
typename  --- 表面其后面的符号是一种数据类型，可以用class代替
T    ---   通用的数据类型，名称可以替换，通常为大写字母

总结：类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板


类模板与函数模板区别主要有两点：
1. 类模板没有自动类型推导的使用方式
2. 类模板在模板参数列表中可以有默认参数

总结：
* 类模板使用只能用显示指定类型方式
* 类模板中的模板参数列表可以有默认参数



*/


// class template
template<class NameType, class AgeType = int>   // 类模板在模板参数列表中可以有默认参数

class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void show_person()
    {
        cout << "name: " << this->m_name << " age: " << this->m_age << endl;
    }

public:
    NameType m_name;
    AgeType m_age;
};


// 类模板使用方式
void test01()
{
    // 指定NameType 为string类型，AgeType 为 int类型
    Person<string, int>P1("Goku", 999);
    P1.show_person();

}


// 类模板没有自动类型推导的使用方式
void test02()
{
	// Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导
	Person <string ,int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
	p.show_person();
}


// 类模板在模板参数列表中可以有默认参数
void test03()
{
	Person <string> p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数
	p.show_person();
}


int main()
{
    test01();

    test02();

    test03();

    return 0;
}