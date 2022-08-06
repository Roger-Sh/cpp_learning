#include <iostream>

using namespace std;


/*
c++通过提供特殊的对象指针，this指针，解决上述问题。**this指针指向被调用的成员函数所属的对象**
this指针是隐含每一个非静态成员函数内的一种指针
this指针不需要定义，直接使用即可
this指针的用途：

*  当形参和成员变量同名时，可用this指针来区分
*  在类的非静态成员函数中返回对象本身，可使用return *this

*/


// this 用法
class Person
{
public:

    // constructor
	Person(int age)
	{
		//1、当形参和成员变量同名时，可用this指针来区分
		this->age = age;
	}


	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		//返回对象本身
		return *this;
	}

	int age;
};



void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}


/*
C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
如果用到this指针，需要加以判断保证代码的健壮性
*/

//空指针访问成员函数
class Person2 {
public:

	void ShowClassName() {
		cout << "我是Person2类!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;
	}

public:
	int mAge;
};

void test02()
{
	Person2 * p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}


/*
const修饰成员函数

**常函数：**

* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象：**

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数

*/

class Person3 {
public:
    // constructor
	Person3() {
		m_A = 0;
		m_B = 0;
	}

	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数  即 const Person * const this;
	// 在成员函数后面加const，修饰的是 this的指向，让指针指向的值也不可以修改
	void ShowPerson() const {
		//const Type* const pointer;

		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
	}

	void MyFunc() {
		m_A = 10000;
	}

public:
	int m_A;
	mutable int m_B;    //可修改 可变的, 不受const限制
};


//const修饰对象  常对象
void test03() {

	// 常对象
	const Person3 p; 		  
	cout << p.m_A << endl;
	// p.m_A = 100; 		//常对象不能修改成员变量的值,但是可以访问
	p.m_B = 100; 			//但是常对象可以修改mutable修饰成员变量

	// 常对象访问成员函数
    p.ShowPerson();
	// p.MyFunc(); //常对象只能调用const的函数， MyFunc() 没有const 修饰


}


int main()
{
    test01();
    test02();
    test03();
    return 0;
}