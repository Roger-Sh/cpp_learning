#include <iostream>
using namespace std;

#include <deque>

/*
### deque容器

#### 3.3.1 deque容器基本概念

**功能：**
* 双端数组，可以对头端进行插入删除操作

**deque与vector区别：**
* vector对于头部的插入删除效率低，数据量越大，效率越低
* deque相对而言，对头部的插入删除速度回比vector快
* vector访问元素时的速度会比deque快,这和两者内部实现有关

deque内部工作原理:
deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据
中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间


#### deque构造函数
**功能描述：**
* deque容器构造

**函数原型：**

* `deque<T>` deqT;              //默认构造形式
* `deque(beg, end);`            //构造函数将[beg, end)区间中的元素拷贝给本身。
* `deque(n, elem);`             //构造函数将n个elem拷贝给本身。
* `deque(const deque &deq);`    //拷贝构造函数

**总结：**deque容器和vector容器的构造方式几乎一致，灵活使用即可
*/


void printDeque(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


// deque 构造
void test01()
{
    // 无参构造函数
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 构造函数将[beg, end)区间中的元素拷贝给本身。
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);


    // 构造函数将n个elem拷贝给本身。
    deque<int> d3(10, 100);
    printDeque(d3);


    // 拷贝构造函数
    deque<int> d4 = d3;
    printDeque(d4);
    
}


int main()
{
    test01();

    return 0;
}