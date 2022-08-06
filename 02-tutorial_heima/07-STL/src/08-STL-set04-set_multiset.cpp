#include <iostream>
#include <set>

using namespace std;

/*
#### set和multiset区别
**学习目标：**
* 掌握set和multiset的区别


**区别：**
* set不可以插入重复数据，而multiset可以
* set插入数据的同时会返回插入结果，表示插入是否成功
* multiset不会检测数据，因此可以插入重复数据


总结：

* 如果不允许插入重复数据可以利用set
* 如果需要插入重复数据利用multiset
*/


// set 和 multiset 的区别
void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if(ret.second)
    {
        cout << "first insert succeed!" << endl;
    }
    else
    {
        cout << "first insert failed!" << endl;
    }

    ret = s.insert(10);
    if (ret.second) 
    {
        cout << "second insert succeed!" << endl;
    }
    else
    {
        cout << "second insert failed!" << endl;
    }

    // multiset
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for(multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

int main()
{
    test01();

    return 0;
}