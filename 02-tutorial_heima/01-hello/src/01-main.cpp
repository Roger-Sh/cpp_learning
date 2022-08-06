#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

// 宏常量
#define day 7


int try_variable()
{
    // 常用变量
    int a = 10;
    cout << "a = " << a << endl;
    cout << "int 类型所占内存空间为： " << sizeof(int) << endl;

    short b = 10;
    cout << "b = " << b << endl;
    cout << "short 类型所占内存空间为： " << sizeof(short) << endl;

    long c = 10;
    cout << "c = " << c << endl;
    cout << "long 类型所占内存空间为： " << sizeof(long) << endl;

    long long d = 10;
    cout << "d = " << d << endl;
    cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;


    float e = 3e-2;
    cout << "e = " << e << endl;
    cout << "float 类型所占内存空间为： " << sizeof(float) << endl;

    double f = 3e-5;
    cout << "f = " << f << endl;
    cout << "double 类型所占内存空间为： " << sizeof(double) << endl;

    char ch = 'a';
    cout << "ch = " << ch << endl;
    cout << "char 类型所占内存空间为： " << sizeof(char) << endl;
    ch = 98;
    cout << "ch = " << ch << endl;

    bool flag = true;
    cout << "flag = " << flag << endl;
    flag = false;
    cout << "flag = " << flag << endl;

    // 转义字符
    cout << "\\" << endl;           // backslash
	cout << "\tHello" << endl;      // tab
	cout << "\n" << endl;           // newline

    // const 常量
    const int month = 12;
    cout << "one year has " << month << " months" << endl;
    // month = 24   // const can not be changed
    // day = 8      // define can not be changed


    return 0;    
}


int try_string()
{
    // 1. c style string 
    char str1[] = "hello world in str1";
    cout << str1 << endl;
    cout << str1[0] << endl;
    cout << str1[3] << endl;

    // 2. c++ style string
    string str2 = "hello world in str2";
    cout << str2 << endl;
    cout << str2[0] << endl;
    cout << str2[3] << endl;

    return 0;
}


int get_data_from_kb()
{
    // input int
    int a = 0;
    cout << "Please enter int a: " << endl;
    cin >> a;
    cout << a << endl;


    // input float
    float b = 0;
    cout << "Please enter float b: " << endl;
    cin >> b;
    cout << b << endl;
    
    // input char
    char ch = 0;
    cout << "Please enter char ch: " << endl;
    cin >> ch;
    cout << ch << endl;
    
    // input string
    string str;
    cout << "Please enter string str: " << endl;
    cin >> str;
    cout << str << endl;

    // input bool
	bool flag = true;
	cout << "Please enter bool flag ：" << endl;
	cin >> flag;
	cout << flag << endl;

    return 0;
}


int try_operator()
{

    // 算术运算符
    int a1 = 10;
	int b1 = 3;

	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;    // 两个整数相除结果依然是整数
    cout << a1 % b1 << endl;    // 小数无法取模
    cout << a1++ << endl;       // 后置递增  
    cout << ++b1 << endl;       // 前置递增

    // 赋值运算符
    int a2 = 10;
    a2 += 2;
    cout << a2 << endl;
    a2 -= 2;
    cout << a2 << endl;
    a2 *= 2;
    cout << a2 << endl;
    a2 /= 2;
    cout << a2 << endl;
    a2 %= 2;
    cout << a2 << endl;

    // 比较运算符
    int a3 = 10;
    int b3 = 20;
	cout << (a3 == b3) << endl; // 0 
	cout << (a3 != b3) << endl; // 1
	cout << (a3 > b3) << endl; // 0
	cout << (a3 < b3) << endl; // 1
	cout << (a3 >= b3) << endl; // 0
	cout << (a3 <= b3) << endl; // 1

    // 逻辑运算符
    int a4 = 10;
    int b4 = 10;
    cout << !a4 << endl;
    cout << (a4 && b4) << endl;
    cout << (a4 && !b4) << endl;
    cout << (!a4 && !b4) << endl;
    cout << (a4 || b4) << endl;
    cout << (a4 || !b4) << endl;
    cout << (!a4 || !b4) << endl;

    // 三目运算符
    int a5 = 10;
	int b5 = 20;
	int c5 = 0;

	c5 = a5 > b5 ? a5 : b5;
	cout << "c5 = " << c5 << endl;

	//C++中三目运算符返回的是变量,可以继续赋值

	(a5 > b5 ? a5 : b5) = 100;

	cout << "a5 = " << a5 << endl;
	cout << "b5 = " << b5 << endl;
	cout << "c5 = " << c5 << endl;

    return 0;

}


int try_if()
{
	int score = 700;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
	}
	else if (score > 500)
	{
		cout << "我考上了二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "我考上了三本大学" << endl;
	}
	else
	{
		cout << "我未考上本科" << endl;
	}

    return 0;
}


int try_switch()
{
    int score = 9.5;

	switch (score)
	{
	case 10:
	case 9:
		cout << "经典" << endl;
		break;
	case 8:
		cout << "非常好" << endl;
		break;
	case 7:
	case 6:
		cout << "一般" << endl;
		break;
	default:
		cout << "烂片" << endl;
		break;
	}

    return 0;
}


int try_while()
{
    int num = 0;
	while (num < 10)
	{
		cout << "num = " << num << endl;
		num++;
	}
	
	return 0;
}


int try_do_while()
{
    int num = 0;

	do
	{
		cout << num << endl;
		num++;

	} while (num < 10);
	
	return 0;
}


int try_for()
{
    for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	
	return 0;
}


int print_multi_table()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < i+1; j++)
        {
            cout << i << " x " << j << " = " << i*j << " "; 
        }   
        cout << endl; 
    }

    return 0;
}


int try_break_continue()
{
    // break in for loop
    for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break; //跳出循环语句
		}
		cout << i << endl;
	}

    // continue in for loop
    for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << endl;
	}

    return 0;
}


int try_array()
{
	//定义方式1
	//数据类型 数组名[元素个数];
	int score[10];

	//利用下标赋值
	score[0] = 100;
	score[1] = 99;
	score[2] = 85;

	//利用下标输出
	cout << score[0] << endl;
	cout << score[1] << endl;
	cout << score[2] << endl;


	//第二种定义方式
	//数据类型 数组名[元素个数] =  {值1，值2 ，值3 ...};
	//如果{}内不足10个数据，剩余数据用0补全
	int score2[10] = { 100, 90,80,70,60,50,40,30,20,10 };
	
	//逐个输出
	cout << score2[0] << endl;
	cout << score2[1] << endl;

	//一个一个输出太麻烦，因此可以利用循环进行输出
	for (int i = 0; i < 10; i++)
	{
		cout << score2[i] << endl;
	}

	//定义方式3
	//数据类型 数组名[] =  {值1，值2 ，值3 ...};
	int score3[] = { 100,90,80,70,60,50,40,30,20,10 };

	for (int i = 0; i < 10; i++)
	{
		cout << score3[i] << endl;
	}

    // 数组长度
    cout << sizeof(score) << endl;
    cout << sizeof(score[0]) << endl;
    cout << sizeof(score) / sizeof(score[0]) << endl;
    cout << end(score) << endl;
    cout << begin(score) << endl;
    cout << end(score) - begin(score) << endl;

	return 0;
}


int try_bubble_sort()
{
    int arr[9] = {4,2,8,0,5,7,1,3,9};

    for (int i = 0; i < 9 - 1; i++)
    {
        for (int j = 0; j < 9 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp; 
            }
        }  
    }

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

 int try_2d_array()
 {
    //方式1  
	//数组类型 数组名 [行数][列数], 不赋值会随机给个数字
	int arr[2][3];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//方式2 
	//数据类型 数组名[行数][列数] = { {数据1，数据2 } ，{数据3，数据4 } };
	int arr2[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	//方式3
	//数据类型 数组名[行数][列数] = { 数据1，数据2 ,数据3，数据4  };
	int arr3[2][3] = { 1,2,3,4,5,6}; 
	//方式4 
	//数据类型 数组名[][列数] = { 数据1，数据2 ,数据3，数据4  };
	int arr4[][3] = { 1,2,3,4,5,6 };
	

    // 二维数组 内存大小，元素个数
    cout << "二维数组大小： " << sizeof(arr) << endl;
	cout << "二维数组一行大小： " << sizeof(arr[0]) << endl;
	cout << "二维数组元素大小： " << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
    cout << "二维数组元素个数 " << sizeof(arr) / sizeof(arr[0][0]) << endl;

	//地址
	cout << "二维数组首地址：" << arr << endl;
	cout << "二维数组第一行地址：" << arr[0] << endl;
	cout << "二维数组第二行地址：" << arr[1] << endl;

	cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;


	return 0;
 }



int main() 
{
    cout << "Hello, World!!!!" << endl;
    
    

    try_variable();

    try_string();
    
    // get_data_from_kb();

    try_operator();

    try_if();

    try_switch();

    try_while();

    try_for();

    print_multi_table();

    try_break_continue();

    try_array();

    try_bubble_sort();

    try_2d_array();

    return 0;
}
