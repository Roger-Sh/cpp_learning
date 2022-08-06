#include <iostream>

using namespace std;

/*
结论： 	父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到
	   父类中所有非静态成员属性都会被子类继承
*/


class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
    // 父类的私有成员只是被隐藏了，但还是会被继承到
	cout << "sizeof Son = " << sizeof(Son) << endl;     // size 16,
}


int main()
{
    test01();


    return 0;
}
