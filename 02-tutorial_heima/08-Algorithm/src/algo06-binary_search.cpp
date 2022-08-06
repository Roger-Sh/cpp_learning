/*
#### binary_search
**功能描述：**
* 查找指定元素是否存在

**函数原型：**
- `bool binary_search(iterator beg, iterator end, value);  `
  // 查找指定的元素，查到 返回true  否则false
  // 注意: 在**无序序列中不可用**
  // beg 开始迭代器
  // end 结束迭代器
  // value 查找的元素

**总结：**二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列

*/

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

void test01()
{
    // 准备数据
    std::vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    } 

    // 二分查找
    bool ret = std::binary_search(v.begin(), v.end(), 2);
    if(ret)
    {
        std::cout << "Find: " << std::endl;
    }
    else
    {
        std::cout << "Didn't find." << std::endl;
    }
}

int main()
{
    test01();

    return 0;
}