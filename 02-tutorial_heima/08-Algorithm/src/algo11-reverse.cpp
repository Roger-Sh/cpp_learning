/*
#### reverse
**功能描述：**
* 将容器内元素进行反转

**函数原型：**
- `reverse(iterator beg, iterator end);  `
  // 反转指定范围的元素
  // beg 开始迭代器
  // end 结束迭代器
*/


#include <iostream>
#include <vector>
#include <algorithm>


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
	std::vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	std::cout << "反转前： " << std::endl;
	std::for_each(v.begin(), v.end(), myPrint());
	std::cout << std::endl;

	std::cout << "反转后： " << std::endl;

	std::reverse(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), myPrint());
	std::cout << std::endl;
}


int main()
{
    test01();

    return 0;
}