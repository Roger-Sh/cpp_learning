#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>


/*
容器：      `vector`
算法：      `for_each`
迭代器：    `vector<int>::iterator`

*/


void my_print(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建vector容器对象，并通过模板参数指定容器中存放的数据类型
    vector<int> v;

    // 向容器中存放数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();

    // 第一种遍历方式
    while (pBegin != pEnd)
    {
        cout << *pBegin << endl;
        pBegin++;
    }
    cout << endl;
    
    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;

    // 第三种遍历方式, 使用STL提供的标准遍历算法
    for_each(v.begin(), v.end(), my_print);     // 将每个元素的值传入my_print()
    

}



int main()
{
    test01();
    return 0;
}