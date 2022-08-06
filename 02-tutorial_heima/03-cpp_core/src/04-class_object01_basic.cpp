#include <iostream>

using namespace std;

const double PI = 3.14;

/*
C++面向对象的三大特性为：==封装、继承、多态==

封装的意义：
* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制
* 类在设计时，可以把属性和行为放在不同的权限下，加以控制
    访问权限有三种：

    1. public        公共权限  
    2. protected 保护权限
    3. private      私有权限


    在C++中 struct和class唯一的**区别**就在于 **默认的访问权限不同**
    区别：
    * struct 默认权限为公共
    * class   默认权限为私有


*/

// 封装 示例-圆
class Circle
{
public:                     // 访问权限, 公共权限

    // 属性, attribution
    int m_r;                // 半径

    // 方法, method
    double calculateZC()    // 求周长
    {
        // 2 * pi * r
        return 2*PI*m_r;
    }

};

// 封装 示例-学生
class Student
{
public:
    string m_name;
    int m_id;

public:

    void setName(string name)
    {
        m_name = name;
    }

    void setID(int id)
    {
        m_id = id;
    }

    void showStudent()
    {
        cout << "name: " << m_name << " ID: " << m_id << endl;
    }

};


// 类的成员访问权限
class Person
{

// 公共权限
public:
    string m_Name;

// 保护权限
protected:
    string m_Car;

// 私有权限
private:
    int m_Password;

// 公共权限
public:
    void func()
    {
        m_Name = "Zhang San";
        m_Car = "Audi";
        m_Password = 123456;

        cout << "name: " << m_Name << " car: " << m_Car << " password: " << m_Password << endl;
    }
};


// 类与结构体的区别,类的默认访问权限是私有,结构体的默认访问权限是公共
class C1
{
	int  m_A; //默认是私有权限
};

struct C2
{
	int m_A;  //默认是公共权限
};


// 控制类的成员属性权限
class Person2 {
public:

	//姓名设置可读可写
	void setName(string name) {
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}


	//获取年龄 
	int getAge() {
		return m_Age;
	}
	//设置年龄
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "你个老妖精!" << endl;
			return;
		}
		m_Age = age;
	}

	//情人设置为只写
	void setLover(string lover) {
		m_Lover = lover;
	}

private:
	string m_Name; //可读可写  姓名
	
	int m_Age; //只读  年龄

	string m_Lover; //只写  情人
};


int main()
{
    // 通过圆类,创建圆的对象
    Circle c1;
    c1.m_r = 10;

    cout << "圆的周长: " << c1.calculateZC() << endl;


    // 通过学生类,创建学生对象
    Student stu1;
    stu1.setName("Shan");
    stu1.setID(1);
    stu1.showStudent();


    // Person类, 尝试不同权限
    Person p1;
    p1.m_Name = "Lisi";     // 公共权限可以修改
    cout << p1.m_Name << endl;
    // p.m_Car = "Benz";    // 保护权限无法访问
    // p.m_Password = 123;  // 私有权限无法访问
    p1.func();              // 保护权限和私有权限可以通过类内部的方法访问


    // 类与结构体的默认访问权限
    C1 cc1;             // 通过类创建对象
    // cc1.m_A = 10;    // 错误,类的默认访问权限为私有,无法访问

    C2 cc2;             // 通过结构体创建对象
    cc2.m_A = 10;       // 结构体的默认访问权限为公共,可以访问


    // 设置类的属性为私有,通过公共方法访问私有属性
    Person2 p2;
	//姓名设置
	p2.setName("张三");
	cout << "姓名： " << p2.getName() << endl;

	//年龄设置
	p2.setAge(50);
	cout << "年龄： " << p2.getAge() << endl;

	//情人设置
	p2.setLover("苍井");
	//cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取


    return 0;
}