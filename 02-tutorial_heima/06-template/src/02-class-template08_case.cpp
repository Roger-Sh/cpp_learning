#include<iostream>
using namespace std;
#include<string>

#include "../head/myArray.hpp"

/*

#### 类模板案例

案例描述:  实现一个通用的数组类，要求如下：

* 可以对内置数据类型以及自定义数据类型的数据进行存储
* 将数组中的数据存储到堆区
* 构造函数中可以传入数组的容量
* 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
* 提供尾插法和尾删法对数组中的数据进行增加和删除
* 可以通过下标的方式访问数组中的元素
* 可以获取数组中当前元素个数和数组的容量

*/


// 打印int数组
void printIntArray(MyArray<int>& arr)
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// 测试内置数据类型
//测试内置数据类型
void test01()
{
	MyArray<int> array1(10);            // 容量10
	for (int i = 0; i < 10; i++)
	{
		array1.push_back(i);
	}
	cout << "array1打印输出：" << endl;
	printIntArray(array1);
	cout << "array1的大小：" << array1.get_size() << endl;
	cout << "array1的容量：" << array1.get_capacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);        // 拷贝构造
	array2.pop_back();
	cout << "array2打印输出：" << endl;
	printIntArray(array2);
	cout << "array2的大小：" << array2.get_size() << endl;
	cout << "array2的容量：" << array2.get_capacity() << endl;
}


//测试自定义数据类型
class Person {
public:
	Person() {} 
		Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};


void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.get_size(); i++) {
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}
}


void test02()
{
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.push_back(p1);
	pArray.push_back(p2);
	pArray.push_back(p3);
	pArray.push_back(p4);
	pArray.push_back(p5);

	printPersonArray(pArray);

	cout << "pArray的大小：" << pArray.get_size() << endl;
	cout << "pArray的容量：" << pArray.get_capacity() << endl;

}


int main()
{
    test01();
    test02();

    return 0;

}