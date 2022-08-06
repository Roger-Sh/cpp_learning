/*
### 5.5 常用算术生成算法
**学习目标：**
- 掌握常用的算术生成算法
**注意：**
* 算术生成算法属于小型算法，使用时包含的头文件为 `#include <numeric>`


**算法简介：**
- `accumulate`      // 计算容器元素累计总和
- `fill`                 // 向容器中添加元素

#### 5.5.1 accumulate
**功能描述：**
*  计算区间内 容器元素累计总和
**函数原型：**
- `accumulate(iterator beg, iterator end, value);  `
  // 计算容器元素累计总和
  // beg 开始迭代器
  // end 结束迭代器
  // value 起始值
**总结：**accumulate使用时头文件注意是 numeric，这个算法很实用


#### 5.5.2 fill
**功能描述：**
* 向容器中填充指定的元素
**函数原型：**
- `fill(iterator beg, iterator end, value);  `
  // 向容器中填充元素
  // beg 开始迭代器
  // end 结束迭代器
  // value 填充的值
**总结：**利用fill可以将容器区间内元素填充为 指定的值
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void test01_accumulate()
{
    vector<int> v;

    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }
    
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << total << endl;

}


class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test02_fill()
{
    vector<int> v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}


int main()
{
    test01_accumulate();

    test02_fill();

    return 0;
}