/*
#### merge
**功能描述：**
* 两个容器元素合并，并存储到另一容器中
**函数原型：**
- `merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
  // 容器元素合并，并存储到另一容器中
  // 注意: 两个容器必须是**有序的**
  // beg1   容器1开始迭代器
  // end1   容器1结束迭代器
  // beg2   容器2开始迭代器
  // end2   容器2结束迭代器
  // dest    目标容器开始迭代器

*/


#include <algorithm>
#include <vector>
#include <iostream>

class myPrint
{
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};


void test01()
{
    // 准备数据
    std::vector<int> v1;
    std::vector<int> v2;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
    }

    // 合并数据
    std::vector<int> vTarget;
    // 提前开辟空间
    vTarget.resize(v1.size() + v2.size());
    // 合并
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    std::for_each(vTarget.begin(), vTarget.end(), myPrint());
    std::cout << std::endl;
}

int main()
{
    test01();

    return 0;
}



