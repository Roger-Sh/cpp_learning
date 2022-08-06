#include <iostream>

using namespace std;


/*
**继承方式一共有三种：**
* 公共继承
* 保护继承
* 私有继承


父类 private 子类都无法访问

公共继承，子类可以访问父类的public，protected，保持原样
保护继承，子类可以访问父类的public，protected，都变成protected
私有继承，子类可以访问父类的public，protected，都变为private

总结：
	公共，类内类外都可以访问
	保护，本类和派生类可以访问
	私有，只有本类可以访问

*/


class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};


// 公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A;        // 可访问 public， 		权限不变
        m_B;        // 可访问 protected		权限不变
        // m_C;     // 不可访问 private
    }
};

void myClass()
{
    Son1 s1;
    s1.m_A;     	// 类外只能访问到公共权限
    // s1.m_B;		// 无法访问到protected权限
}


//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2:protected Base2
{
public:
	void func()
	{
		m_A; 		//可访问 public 权限		权限变为protected
		m_B; 		//可访问 protected 权限		权限变为protected
		//m_C; 		//不可访问 private 权限
	}
};

void myClass2()
{
	Son2 s;
	// s.m_A; 		// 类外不可访问protected
	// s.m_B		// 类外不可访问protected
	// s.m_C;		// 不可访问private

}


//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3:private Base3
{
public:
	void func()
	{
		m_A; //可访问 public权限		权限变为private
		m_B; //可访问 protected权限		权限变为private
		//m_C; //不可访问
	}
};


class GrandSon3 :public Son3
{
public:
	void func()
	{
		//Son3是私有继承Base3，所以继承Son3的属性在GrandSon3中都无法访问到
		//m_A;
		//m_B;
		//m_C;
	}
};

int main()
{

}