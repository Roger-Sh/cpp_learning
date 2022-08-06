#include <iostream>
#include <set>

using namespace std;

/*
#### set查找和统计
**功能描述：**
* 对set容器进行查找数据以及统计数据


**函数原型：**
* `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
* `count(key);`                //统计key的元素个数
*/

void test01()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

    // 查找
    set<int>::iterator pos = s1.find(30);

    if(pos != s1.end())
    {
        cout << " found element: " << *pos <<  endl;
    }
    else
    {
        cout << "didn't find element" << endl;
    }

    // count
    int num = s1.count(30);
    cout << "element 30 has num = " << num << endl;

}


int main()
{
    test01();

    return 0;
}

