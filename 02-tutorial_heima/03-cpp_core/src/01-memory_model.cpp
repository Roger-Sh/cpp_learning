#include <iostream>

using namespace std;

/*
C++程序在执行时，将内存大方向划分为**4个区域**

- 代码区：存放函数体的二进制代码，由操作系统进行管理的
- 全局区：存放全局变量和静态变量以及常量， 包括常量区
- 栈区：由编译器自动分配释放, 存放函数的参数值,局部变量等
- 堆区：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收

总结：

* C++中在程序运行前分为全局区和代码区
* 代码区特点是共享和只读
* 全局区中存放全局变量、静态变量、常量
* 常量区中存放 const修饰的全局常量  和 字符串常量
*/



//全局变量 全局区
int g_a = 10;
int g_b = 10;

//全局常量 全局区中的常量区
const int c_g_a = 10;
const int c_g_b = 10;

/*
栈区
​由编译器自动分配释放, 存放函数的参数值,局部变量等
注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
*/
// int * func1()
// {
//     int a = 10； 
//     return &a;
// }


/*
堆区
由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
​在C++中主要利用new在堆区开辟内存
*/
int* func2()
{
	// 利用new创建的数据，会返回该数据对应的类型的指针
    int* a = new int(10);   // 堆区数据利用new关键字进行开辟内存
	return a;               // 返回堆区数据的地址
}

// 堆区例子，堆区开辟数组
void func3()
{
    // 使用 new 开辟空间给一个数组 
    int * arr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i+100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    // 使用 delete[] 释放数组
    delete[] arr;    
}

int main() {

	// 局部变量
	int a = 10;
	int b = 10;

    // 静态变量
	static int s_a = 10;
	static int s_b = 10;

    // 局部常量
	const int c_l_a = 10;
	const int c_l_b = 10;

	// 打印地址
    cout << "局部变量存放在栈区" << endl;
	cout << "局部变量a地址为： " << (long)&a << endl;
	cout << "局部变量b地址为： " << (long)&b << endl;

    cout << "全局变量存放在全局区" << endl;
	cout << "全局变量g_a地址为： " <<  (long)&g_a << endl;
	cout << "全局变量g_b地址为： " <<  (long)&g_b << endl;

    cout << "静态变量存放在全局区" << endl;
	cout << "静态变量s_a地址为： " << (long)&s_a << endl;
	cout << "静态变量s_b地址为： " << (long)&s_b << endl;

    cout << "普通常量，全局常量放在常量区" << endl;
	cout << "字符串常量地址为： " << (long)&"hello world" << endl;
	cout << "字符串常量地址为： " << (long)&"hello world1" << endl;
	cout << "全局常量c_g_a地址为： " << (long)&c_g_a << endl;
	cout << "全局常量c_g_b地址为： " << (long)&c_g_b << endl;

    cout << "局部常量存放在栈区" << endl;
	cout << "局部常量c_l_a地址为： " << (long)&c_l_a << endl;
	cout << "局部常量c_l_b地址为： " << (long)&c_l_b << endl;


    // 栈区，注意不能返回局部变量的地址，栈区的数据由编译器自动释放
    // int *p = func1();
	// cout << *p << endl;
	// cout << *p << endl;


    // 堆区，由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
    // 堆区数据由程序员管理开辟和释放
    // 堆区数据利用new关键字进行开辟内存
	int *p = func2();
	cout << *p << endl;
	cout << *p << endl;
    delete p;           // 使用delete释放堆区数据

    // 堆区示例
    func3();

	return 0;
}