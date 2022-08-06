#include <iostream>

using namespace std;


/*
C++对象模型：
在C++中，类内的成员变量和成员函数分开存储
只有非静态成员变量才属于类的对象上


*/




class Person {
public:

    // constructor
	Person() {
		mA = 0;
	}
	
    //非静态成员变量占对象空间
	int mA;
	
    //静态成员变量不占对象空间
	static int mB; 
	
    //函数也不占对象空间，所有函数共享一个函数实例
	void func() {
		cout << "mA:" << this->mA << endl;
	}

	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};




int main()
{
	cout << sizeof(Person) << endl;     // 只有非静态成员占对象空间

    Person p;
	cout << sizeof(p) << endl;     // 只有非静态成员占对象空间


    return 0;
}