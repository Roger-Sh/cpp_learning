#include <iostream>

using namespace std;


/*
在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
因此可以将虚函数改为**纯虚函数**
纯虚函数语法：`virtual 返回值类型 函数名 （参数列表）= 0 ;`
当类中有了纯虚函数，这个类也称为==抽象类==

**抽象类特点**：

 * 无法实例化对象
 * 子类必须重写抽象类中的纯虚函数，否则也属于抽象类


*/

class Base
{
public:
    //纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;                    // 纯虚函数必须等于0
};


class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func 调用" << endl;
    };
};


void test01()
{
    Base * base = NULL;     //  纯虚函数只能是空指针
    // base = new Base;     // 报错，因为抽象类无法被实例化
    base = new Son;         // 可以实例化子类，通过多态的方式
    base->func();
    delete base;        // 记得销毁


}


int main()
{
    test01();
    
    return 0;
}