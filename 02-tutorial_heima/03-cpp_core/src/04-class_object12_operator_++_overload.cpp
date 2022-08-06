#include <iostream>

using namespace std;



/*
递增运算符重载
作用： 通过重载递增运算符，实现自己的整型数据
> 总结： 前置递增返回引用，后置递增返回值
*/


class MyInteger
{
    // friend func
    friend ostream& operator<<(ostream& out, MyInteger myint);


public:
    
    // constructor    
    MyInteger()
    {
        m_Num = 0;
    }

    // 前置++
    MyInteger& operator++()
    {
        // 先++
        m_Num++;

        // 再返回
        return *this;   // 返回对象的引用
    }

    // 后置++
    MyInteger operator++(int)   // int 为占位参数，用于区分前置还是后置
    {
        // 先记录结果
        MyInteger tmp = *this;  // 记录当前的值，然后让本身的值加1， 但是返回以前的值，以达到先返回后++的效果
        
        // 再递增
        m_Num++;

        // 最后返回初始结果
        return tmp;     // 返回局部对象，不能返回其引用指针，必须返回其值
    }


private:
    int m_Num;


};


// 左移运算符 << 重载
ostream& operator<<(ostream& out, MyInteger myint)
{
    out << myint.m_Num;
    return out;
}




void test01()
{
    MyInteger myInt;
    cout << myInt << endl;      // 0
    cout << ++myInt << endl;    // 1
    cout << myInt << endl;      // 1
    cout << myInt++ << endl;    // 1
    cout << myInt << endl;      // 2
    cout << ++((++myInt)) << endl;    // 4
    cout << myInt << endl;
}   


int main()
{
    test01();

    return 0;
}