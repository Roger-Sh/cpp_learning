/*
#### adjacent_find
**功能描述：**
* 查找相邻重复元素

**函数原型：**
- `adjacent_find(iterator beg, iterator end);  `
  // 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
  // beg 开始迭代器
  // end 结束迭代器

总结：面试题中如果出现查找相邻重复元素，记得用STL中的adjacent_find算法
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

void test01()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
    v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

    // 查找相邻的重复元素
    std::vector<int>::iterator it = std::adjacent_find(v.begin(), v.end());
    if(it == v.end())
    {
        std::cout << "Didn't find!" << std::endl;
    }
    else
    {
        std::cout << "Find adjacent repeat element: " << *it << std::endl;
    }
}

int main()
{
    test01();

    return 0;
}