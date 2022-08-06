/*
#### 函数对象概念

**概念：**
* 重载**函数调用操作符**的类，其对象常称为**函数对象**
* **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**

**本质：**
函数对象(仿函数)是一个**类**，不是一个函数

#### 4.1.2  函数对象使用
**特点：**
* 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
* 函数对象超出普通函数的概念，函数对象可以有自己的状态
* 函数对象可以作为参数传递
*/

#include <iostream>
#include <string>
using namespace std;

// 1. 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test01()
{
    MyAdd myAdd;

    cout << myAdd(10, 10) << endl;
}


// 函数对象可以有自己的状态
class MyPrint
{
public:
    int count;  // 成员变量

public:
    // constructor
    MyPrint()
    {
        count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        count++;    // 统计使用次数
    }
};

void test02()
{
    MyPrint myPrint;
    myPrint("Hello world");
    myPrint("Hello world");
    myPrint("Hello world");
    cout << "myPrint 调用次数：" << myPrint.count << endl;
}

// 函数对象可以作为参数传递
void doPrint(MyPrint &myPrint, string test)
{
    myPrint(test);
}

void test03()
{
    MyPrint myPrint;
    doPrint(myPrint, "Hello C++");
}

int main()
{
    test01();

    test02();

    test03();

    return 0;

}
