/*
### 常用排序算法
**学习目标：**
- 掌握常用的排序算法
**算法简介：**

- `sort`             //对容器内元素进行排序
- `random_shuffle`   //洗牌   指定范围内的元素随机调整次序
- `merge `           // 容器元素合并，并存储到另一容器中
- `reverse`       // 反转指定范围的元素

#### sort
**功能描述：**
* 对容器内元素进行排序
**函数原型：**
- `sort(iterator beg, iterator end, _Pred);  `
  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  //  beg    开始迭代器
  //  end    结束迭代器
  // _Pred   谓词

**总结：**sort属于开发中最常用的算法之一，需熟练掌握

*/


#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


void myPrint(int val)
{
    std::cout << val << " ";
}


void test01()
{
    // 数据准备
    std::vector<int> v;
    v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

    // sort 从小到大
    std::sort(v.begin(), v.end());
    std::for_each(v.begin(), v.end(), myPrint);
    std::cout << std::endl;

    // 从大到小排序
    std::sort(v.begin(), v.end(), std::greater<int>());
    std::for_each(v.begin(), v.end(), myPrint);
    std::cout << std::endl;
}


int main()
{
    test01();

    return 0;
}



