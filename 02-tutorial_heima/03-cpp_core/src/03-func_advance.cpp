#include <iostream>

using namespace std;


// 函数默认参数
//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数

int try_default_arg1(int a, int b = 10, int c = 10)
{
    return a + b + c;
}

//如果函数声明有默认值，函数实现的时候就不能有默认参数
int try_default_arg2(int a = 10, int b = 10);   // 函数声明有默认参数
// int try_default_arg2(int a = 10, int b = 10)    // 函数实现 不能有默认参数
int try_default_arg2(int a, int b)
{
    return a + b;
}


// 函数占位参数
void try_arg3(int a, int) {
	cout << "this is func" << endl;
}



// 函数重载
/*
**作用：**函数名可以相同，提高复用性
**函数重载满足条件：**
* 同一个作用域下
* 函数名称相同
* 函数参数**类型不同**  或者 **个数不同** 或者 **顺序不同**
**注意:**  函数的返回值不可以作为函数重载的条件
*/
//函数重载需要函数都在同一个作用域下
void func()
{
	cout << "func 的调用！" << endl;
}
void func(int a)
{
	cout << "func (int a) 的调用！" << endl;
}
void func(double a)
{
	cout << "func (double a)的调用！" << endl;
}
void func(int a ,double b)
{
	cout << "func (int a ,double b) 的调用！" << endl;
}
void func(double a ,int b)
{
	cout << "func (double a ,int b)的调用！" << endl;
}
//函数返回值不可以作为函数重载条件
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
//}


//函数重载注意事项
//1、引用作为重载条件
void func2(int &a)
{
	cout << "func (int &a) 调用 " << endl;
}

void func2(const int &a)
{
	cout << "func (const int &a) 调用 " << endl;
}

//2、函数重载碰到函数默认参数
void func3(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func3(int a)
{
	cout << "func2(int a) 调用" << endl;
}


int main()
{
    // 函数默认参数
    cout << "return = " << try_default_arg1(20, 20) << endl;
    cout << "return = " << try_default_arg2(100) << endl;


    // 函数占位参数
    try_arg3(10, 10);   // 占位参数必须填补


    // 函数重载
	func();
	func(10);
	func(3.14);
	func(10,3.14);
	func(3.14 , 10);

    int a = 10;
    func2(a);   // 调用引用参数无const
    func2(10);  // 调用引用参数有const 

	//func2(10); //碰到默认参数产生歧义，需要避免

    return 0;
}