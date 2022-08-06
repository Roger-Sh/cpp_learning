#include <iostream>
using namespace std;

// #include "person.h"          //解决方式，包含cpp源文件
// #include "person.cpp" 

#include "../head/person.hpp"   // 解决方式 将声明和实现写在一起，后缀改为hpp




/*
#### 类模板分文件编写

学习目标：

* 掌握类模板成员函数分文件编写产生的问题以及解决方式

问题：
* 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决：
* 解决方式1：直接包含.cpp源文件
* 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp
*/


void test01()
{
	Person<string, int> p("Tom", 10);
	p.show_person();
}

int main() {

	test01();

	return 0;
}