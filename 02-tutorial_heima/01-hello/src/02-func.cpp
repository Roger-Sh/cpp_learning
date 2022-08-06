#include <iostream>
#include <unistd.h>

#include "../head/swap.h"

using namespace std;


//声明可以多次，定义只能一次
//声明
int max(int a, int b);
int max(int a, int b);
//定义
int max(int a, int b)
{
	return a > b ? a : b;
}


// 函数例子, 声明在 head 文件中
void swap(int num1, int num2)
{
    cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}


//函数常见样式
//1、 无参无返
void test01()
{
	//void a = 10; //无类型不可以创建变量,原因无法分配内存
	cout << "this is test01" << endl;
	//test01(); 函数调用
}

//2、 有参无返
void test02(int a)
{
	cout << "this is test02" << endl;
	cout << "a = " << a << endl;
}

//3、无参有返
int test03()
{
	cout << "this is test03 " << endl;
	return 10;
}

//4、有参有返
int test04(int a, int b)
{
	cout << "this is test04 " << endl;
	int sum = a + b;
	return sum;
}


int main()
{
    int a = 10;
	int b = 20;
	swap(a, b);
	cout << "main中的 a = " << a << endl;
	cout << "main中的 b = " << b << endl;
    

    test01();
    test02(10);
    test03();
    test04(1,2);

    cout << max(1,2) << endl;

    
    return 0;
}
