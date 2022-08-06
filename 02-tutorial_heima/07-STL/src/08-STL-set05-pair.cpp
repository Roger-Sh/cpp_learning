#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
#### pair对组创建
**功能描述：**
* 成对出现的数据，利用对组可以返回两个数据

**两种创建方式：**
* `pair<type, type> p ( value1, value2 );`
* `pair<type, type> p = make_pair( value1, value2 );`


总结：
两种方式都可以创建对组，记住一种即可
*/


void test01()
{
    pair<string, int> p(string("Tom"), 20);
    cout << "name: " << p.first << "age: " << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 10);
    cout << "name: " << p2.first << "age: " << p2.second << endl;
}


int main()
{
    test01();

    return 0;
}