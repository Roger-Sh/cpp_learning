#include <iostream>

using namespace std;

/*
重载左移运算符
作用：可以输出自定义数据类型
> 总结：重载左移运算符配合友元可以实现输出自定义数据类型

*/


class Person {
	// 利用友元函数重载<<运算符
	friend ostream& operator<<(ostream& out, Person& p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	// 成员函数 实现不了  p << cout 不是我们想要的效果 p.operator<<(p) 
	// 不会利用成员函数重载 << 运算符
	//void operator<<(Person& p){
	//}

private:
	int m_A;
	int m_B;
};


//全局函数实现左移重载
//ostream对象只能有一个
ostream& operator<<(ostream &out, Person &p) {		// 本质 operator<< (cout, p)
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;		// 为了实现链式编程
}

void test() {

	Person p1(10, 20);

	cout << p1 << " hello world" << endl; //链式编程
}


int main()
{
    test();

    return 0;
}