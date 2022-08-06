#include <iostream>

using namespace std;


/*
有些类与类之间存在特殊的关系
我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。
这个时候我们就可以考虑利用继承的技术，减少重复代码

**总结：**
继承的好处：==可以减少重复的代码==
class A : public B; 
A 类称为子类 或 派生类
B 类称为父类 或 基类


**派生类中的成员，包含两大部分**：
一类是从基类继承过来的，一类是自己增加的成员。
从基类继承过过来的表现其共性，而新增的成员体现了其个性。

*/


//公共页面
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}

};


// Java 页面
class Java : public BasePage
{
public:
    void content()
    {
        cout << "Java tutorial video" << endl;
    }
};


class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python tutorial video" << endl;
    }
};


class CPP : public BasePage
{
public:
    void content()
    {
        cout << "CPP tutorial video" << endl;
    }
};



void test01()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python下载视频页面如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++下载视频页面如下： " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();

};



int main()
{
    test01();

    return 0;
}