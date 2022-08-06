/*
#### random_shuffle
**功能描述：**
* 洗牌   指定范围内的元素随机调整次序

**函数原型：**
- `random_shuffle(iterator beg, iterator end);  `
  // 指定范围内的元素随机调整次序
  // beg 开始迭代器
  // end 结束迭代器

*/

#include <algorithm>
#include <vector>
#include <ctime>
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
    // 随机种子
    srand((unsigned int)time(NULL));
    
    // 准备数据
    std::vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 打印数据
    std::for_each(v.begin(), v.end(), myPrint());
    std::cout << std::endl;

    // random_shuffle
    std::random_shuffle(v.begin(), v.end());
    std::for_each(v.begin(), v.end(), myPrint());
    std::cout << std::endl;

}

int main()
{
    test01();

    return 0;
}