#pragma once
#include <iostream>
using namespace std;
#include <string>


// 模板函数Person
template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    
    void show_person();

public:
    T1 m_name;
    T2 m_age;
};


// 构造函数 类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}

// 成员函数 类外实现
template<class T1, class T2>
void Person<T1, T2>::show_person()
{
    cout << "Name: " << this->m_name << " Age: " << this->m_age << endl;
}