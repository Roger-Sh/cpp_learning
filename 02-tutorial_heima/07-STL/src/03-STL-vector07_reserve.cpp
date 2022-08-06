#include <iostream>
using namespace std;
#include <vector>

/*
#### vector预留空间

**功能描述：**
* 减少vector在动态扩展容量时的扩展次数

**函数原型：**
* `reserve(int len);`//容器预留len个元素长度，预留位置不初始化，元素不可访问。
总结：如果数据量较大，可以一开始利用reserve预留空间

vector 的reserve增加了vector的capacity，但是它的size没有改变！而resize改变了vector的capacity同时也增加了它的size！
原因如下：
    reserve是容器预留空间，但在空间内不真正创建元素对象，所以在没有添加新的对象之前，
    不能引用容器内的元素。加入新的元素时，要调用push_back()/insert()函数。
    resize是改变容器的大小，且在创建对象，因此，调用这个函数之后，就可以引用容器内的对象了，
    因此当加入新的元素时，用operator[]操作符，或者用迭代器来引用元素对象。此时再调用push_back()函数，是加在这个新的空间后面的。
    两个函数的参数形式也有区别的，reserve函数之后一个参数，即需要预留的容器的空间；
    resize函数可以有两个参数，第一个参数是容器新的大小， 第二个参数是要加入容器中的新元素，如果这个参数被省略，那么就调用元素对象的默认构造函数。
*/

void test01()
{
    vector<int> v;

    // reserve space
    v.reserve(100000);

    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if(p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num: " << num << endl;   
}


int main()
{
    test01();

    return 0;
}