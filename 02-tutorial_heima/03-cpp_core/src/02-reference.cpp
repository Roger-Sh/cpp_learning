#include <iostream>

using namespace std;


/*
引用
作用：给变量起别名
本质：引用的本质在c++内部实现是一个指针常量.
语法：数据类型 &别名 = 原名

注意：
* 引用必须初始化
* 引用在初始化后，不可以改变

引用作函数参数：
总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单

引用作函数返回值：
作用：引用是可以作为函数的返回值存在的
注意：不要返回局部变量引用
用法：函数调用作为左值
*/


//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
// 作用：函数传参时，可以利用引用的技术让形参修饰实参
// 优点：可以简化指针修改实参
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


//返回局部变量引用， 错误使用
// int& test01() {
//     int a = 10; //局部变量
//     return a;
// }

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}


// 常量引用
// 常量引用使用的场景，通常用来修饰形参
void showValue(const int& v) {
    //v += 10;      // 无法修改 常量引用
    cout << v << endl;
}



int main()
{
    // 引用
    int a = 10;
    int &b = a;     // b为a的引用
    // int &c;         // 错误，引用必须初始化
    int &c = a;     // 一旦初始化就不可更改
    c = b;          // 这是赋值操作，不是更改引用

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    b = 100;    // b就是a的引用，就是a的另一个名字，所以修改b同时修改了a
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;


	int a1 = 10;
	int b1 = 20;




    // 值传递，函数内变化不影响外部变化
	mySwap01(a1, b1);
	cout << "a1:" << a1 << " b1:" << b1 << endl;

    // 地址传递，函数内变化会影响外部变化
	mySwap02(&a1, &b1);
	cout << "a1:" << a1 << " b1:" << b1 << endl;

    // 引用传递，函数内变化会影响外部变化，相比地址传递，传值时更方便
	mySwap03(a1, b1);
	cout << "a1:" << a1 << " b1:" << b1 << endl;



    //不能返回局部变量的引用
    // int& ref = test01();
    // cout << "ref = " << ref << endl;
    // cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;    // 将1000存放到函数test02()的内存位置

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;



    // 常量引用
    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
	const int& ref = 10;
	//ref = 100;  //加入const后不可以修改变量
	cout << ref << endl;
    //函数中利用常量引用防止误操作修改实参
	int d = 10;
	showValue(d);
}