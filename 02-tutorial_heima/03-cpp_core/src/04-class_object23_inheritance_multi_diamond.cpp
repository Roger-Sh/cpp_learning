#include <iostream>

using namespace std;

/*
**菱形继承概念：**
​	两个派生类继承同一个基类
​	又有某个类同时继承者两个派生类
​	这种继承被称为菱形继承，或者钻石继承

**菱形继承问题：**
1.     羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
2.     草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。

总结：
* 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
* 利用虚继承可以解决菱形继承问题

*/


class Animal
{
public:
    int m_Age;
};

// 菱形继承导致了数据有两份，资源浪费
//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;
    st.m_Age = 300;

    // 所有的m_Age 都是一个内容
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;

}



int main()
{
    test01();

    return 0;

}