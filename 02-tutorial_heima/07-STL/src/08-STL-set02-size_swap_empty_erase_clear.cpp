
#include <iostream>
#include <set>

using namespace std;

/*
#### set大小和交换
**功能描述：**
* 统计set容器大小以及交换set容器

**函数原型：**
* `size();`          //返回容器中元素的数目
* `empty();`        //判断容器是否为空
* `swap(st);`      //交换两个集合容器


#### set插入和删除
**功能描述：**
* set容器进行插入数据和删除数据

**函数原型：**
* `insert(elem);`           //在容器中插入元素。
* `clear();`                    //清除所有元素
* `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
* `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
* `erase(elem);`            //删除容器中值为elem的元素。


#### set插入和删除
**功能描述：**
* set容器进行插入数据和删除数据

**函数原型：**
* `insert(elem);`           //在容器中插入元素。
* `clear();`                    //清除所有元素
* `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
* `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
* `erase(elem);`            //删除容器中值为elem的元素。

*/


void printSet(set<int> &s)
{
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
	
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

    if (s1.empty())
    {
        cout << "s1 is empty" << endl;
    }
    else
    {
        cout << "s1 is not empty" << endl;
        cout << "size of s1: " << s1.size() << endl;
    }
}

void test02()
{
    set<int> s1;

    s1.insert(10);  
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

    set<int> s2;

	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	cout << endl;

	cout << "交换后" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}


//插入和删除
void test03()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//删除
	s1.erase(s1.begin());
	printSet(s1);

	s1.erase(30);
	printSet(s1);

	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}

int main()
{
    test01();

    test02();

	test03();
	
    return 0;

}