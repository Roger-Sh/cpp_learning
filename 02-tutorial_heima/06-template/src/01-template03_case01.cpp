#include <iostream>
using namespace std;


/*
案例描述：

* 利用函数模板封装一个排序的函数，可以对**不同数据类型数组**进行排序
* 排序规则从大到小，排序算法为**选择排序**
* 分别利用**char数组**和**int数组**进行测试

*/

//交换的函数模板
template<typename T>
void mySwap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}


//利用选择排序，进行对数组从大到小的排序
template<class T> // 也可以替换成typename
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //最大数的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //如果最大数的下标不是i，交换两者
		{
			mySwap(arr[max], arr[i]);
		}
	}
}


// 打印数组
template<typename T>
void printArray(T arr[], int len) {

	for (int i = 0; i < len; i++) {		// 字符串最后一位是终止符，不能打印，打印会结束程序
		if(arr[i] != '\0')				// 加入判断，如果是 '\0' 则跳过
		{
			cout << arr[i] << " ";
		}
		else
		{
			cout << endl;
		}
	}
}


// 测试字符数组
void test01()
{
	//测试char数组
	char charArr[] = "bdcfeagh";	// 最后一位\0 不可见
	int num = sizeof(charArr) / sizeof(char);
	cout << num << endl;
	mySort(charArr, num);
	printArray(charArr, num);
}


// 测试int数组
void test02()
{
	//测试int数组
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	int num = sizeof(intArr) / sizeof(int);
	cout << num << endl;
	mySort(intArr, num);
	printArray(intArr, num);
}

int main()
{

	test01();

	test02();

	return 0;
}