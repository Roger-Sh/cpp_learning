/*
#### 内建函数对象意义

**概念：**
* STL内建了一些函数对象

**分类:**
* 算术仿函数
* 关系仿函数
* 逻辑仿函数

**用法：**
* 这些仿函数所产生的对象，用法和一般函数完全相同
* 使用内建函数对象，需要引入头文件 `#include<functional>`


#### 算术仿函数

**功能描述：**
* 实现四则运算
* 其中negate是一元运算，其他都是二元运算
**仿函数原型：**
* `template<class T> T plus<T>`             //加法仿函数
* `template<class T> T minus<T>`            //减法仿函数
* `template<class T> T multiplies<T>`       //乘法仿函数
* `template<class T> T divides<T>`          //除法仿函数
* `template<class T> T modulus<T>`          //取模仿函数
* `template<class T> T negate<T>`           //取反仿函数

#### 关系仿函数

**功能描述：**
- 实现关系对比
**仿函数原型：**
* `template<class T> bool equal_to<T>`          //等于
* `template<class T> bool not_equal_to<T>`      //不等于
* `template<class T> bool greater<T>`           //大于
* `template<class T> bool greater_equal<T>`     //大于等于
* `template<class T> bool less<T>`              //小于
* `template<class T> bool less_equal<T>`        //小于等于

#### 逻辑仿函数

**功能描述：**
- 实现逻辑运算
**函数原型：**
* `template<class T> bool logical_and<T>`              //逻辑与
* `template<class T> bool logical_or<T>`                //逻辑或
* `template<class T> bool logical_not<T>`              //逻辑非


*/

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// STL自带算术仿函数
void test01()
{
    std::negate<int> neg;
    cout << neg(50) << endl;

    std::plus<int> p;
    cout << p(10, 20) << endl;
}

// 自定义关系仿函数
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

// STL自带关系仿函数
void test02()
{
    vector<int> v;

    v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//自己实现仿函数
	//sort(v.begin(), v.end(), MyCompare());
	//STL内建仿函数  大于仿函数
	sort(v.begin(), v.end(), std::greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


// STL自带逻辑仿函数
void test03()
{
    vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 使用逻辑非仿函数，将v容器的内容搬到v2中
    vector<bool> v2;
    v2.resize(v.size());
    std::transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for(vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

int main()
{
    test01();

    test02();

    test03();

    return 0;
}