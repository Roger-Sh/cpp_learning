#include <iostream>
using namespace std;
#include <vector>

/*
#### vector容量和大小

**功能描述：**
* 对vector容器的容量和大小操作



**函数原型：**
* `empty(); `                   //判断容器是否为空
* `capacity();`                 //容器的容量
* `size();`                     //返回容器中元素的个数
* `resize(int num);`            //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
  ​					             //如果容器变短，则末尾超出容器长度的元素被删除。

* `resize(int num, elem);`      //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
  ​				                 //如果容器变短，则末尾超出容器长度的元素被删除

  总结：

* 判断是否为空  --- empty
* 返回元素个数  --- size
* 返回容器容量  --- capacity
* 重新指定大小  ---  resize
*/


void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if(v1.empty())
    {
        cout << "v1 is empty" << endl;
    }
    else
    {
        cout << "v1 is not empty" << endl;
        cout << "capacity of v1 is: " << v1.capacity() << endl;
        cout << "size of v1 is: " << v1.size() << endl;
    }


    // resize() 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(15, 10);      // 位置更多，空余位置用10填充
    printVector(v1);

    v1.resize(5);           // 位置更少，超出部分被删除
    printVector(v1);
    cout << "capacity of v1 is: " << v1.capacity() << endl;
    
}


int main()
{
    test01();

    return 0;

}