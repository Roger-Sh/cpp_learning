#include <iostream>

using namespace std;


/*
c++编译器至少给一个类添加4个函数

1. 默认构造函数(无参，函数体为空)
2. 默认析构函数(无参，函数体为空)
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=, 对属性进行值拷贝

如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题


*/


class Person
{
public:

    // constructor
    Person(int age)
    {
        // 将年龄数据开辟到堆区
        m_Age = new int(age);
    }


    // 重载赋值运算符
    Person& operator=(Person &p)
    {
        // 应先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }

        //当有堆区的数据时，在进行对象赋值操作之后，会多次释放同一个堆区内存，造成问题
        //需要使用深拷贝，不只是简单的内存指针拷贝，同时还新开辟堆区空间，避免之后的多次释放
        //编译器提供的代码是浅拷贝, 简单的赋值拷贝，
		//m_Age = p.m_Age;

        // 提供深拷贝，在堆区重新申请空间，进行拷贝操作
        m_Age = new int(*p.m_Age);

        // 返回对象自身
        return *this;
    }

    // deconstrcutor
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;   // 手动开启的堆区数据要在析构函数中手动释放
            m_Age = NULL;
        }
    }


    int *m_Age;


};

void test01()
{
    // 默认int的赋值
    // int a = 10;
	// int b = 20;
	// int c = 30;

	// c = b = a;
	// cout << "a = " << a << endl;
	// cout << "b = " << b << endl;
	// cout << "c = " << c << endl;

    // Person类的赋值
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1;   // 赋值操作

    cout << " p1 age: " << *p1.m_Age << endl;
    cout << " p2 age: " << *p2.m_Age << endl;
    cout << " p3 age: " << *p3.m_Age << endl;
}



int main()
{
    test01();
    return 0;
}