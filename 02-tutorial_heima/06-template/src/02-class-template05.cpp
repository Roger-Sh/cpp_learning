#include <iostream>
using namespace std;

#include <string>

/*
#### 类模板成员函数类外实现
学习目标：能够掌握类模板中的成员函数类外实现

总结：类模板中成员函数类外实现时，需要加上模板参数列表
*/


// 类模板中成员函数类外实现
template<class T1, class T2>
class Person
{
public:
    // 成员函数类内声明
    Person(T1 name, T2 age);
    void show_person();

public:
    T1 m_name;
    T2 m_age;
};

// 构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}

// 成员函数类外实现
template<class T1, class T2>
void Person<T1, T2>::show_person()
{
    cout << "Name: " << this->m_name << " Age: " << this->m_age << endl;
}

void test01()
{
    Person<string, int> p("Roger", 28);
    p.show_person();
}

int main()
{
    test01();

    return 0;
}