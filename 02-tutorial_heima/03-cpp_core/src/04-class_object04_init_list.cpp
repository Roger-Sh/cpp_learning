#include <iostream>

using namespace std;

/*
C++提供了初始化列表语法，用来初始化属性
语法：`构造函数()：属性1(值1),属性2（值2）... {}`




*/


class Person1
{
    public:
	////传统方式初始化
	//Person(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表方式初始化
	Person1(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
	
    // print person
    void PrintPerson() {
		cout << "mA:" << m_A << endl;
		cout << "mB:" << m_B << endl;
		cout << "mC:" << m_C << endl;
	}

private:
	int m_A;
	int m_B;
	int m_C;
};


void try_init_list()
{
    Person1 p(1, 2, 3);
	p.PrintPerson();
}

int main()
{
    try_init_list();
}