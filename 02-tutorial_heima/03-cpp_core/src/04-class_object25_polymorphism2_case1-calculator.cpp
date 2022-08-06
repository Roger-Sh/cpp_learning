#include <iostream>

using namespace std;

/*
案例描述：

分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

多态的优点：

* 代码组织结构清晰
* 可读性强
* 利于前期和后期的扩展以及维护

> 总结：C++开发提倡利用多态设计程序架构，因为多态优点很多



*/


// 普通实现
// 如果要提供新的运算，需要修改源码
// 在真实开发中，提倡开闭原则
// 开闭原则： 对扩展进行开发，对修改进行关闭
class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }

    }

public:
    int m_Num1;
    int m_Num2;

};


void test01()
{
	//普通实现测试
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}


// 多态实现
// 抽象计算器类
// 多态优点： 代码组织结构清晰，可读性强，利于前后期扩展维护

class AbstractCalculator
{
public:
    virtual int getResult()     // 抽象类的虚函数
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

// 加法计算器 继承计算器
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器 继承计算器
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};


// 乘法计算器 继承计算器
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};


void test02()
{
	//创建加法计算器
	AbstractCalculator *abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;  //用完了记得销毁

	//创建减法计算器
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;  

	//创建乘法计算器
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}

int main()
{
    // 普通计算器
    test01();

    // 多态实现抽象类计算器
    test02();

    return 0;
}