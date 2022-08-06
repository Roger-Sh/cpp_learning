#include <iostream>

using namespace std;


// 指针
int try_pointer()
{
    // 定义指针，得到指针
    int a = 10; // define var
    int *p;    // define pointer var
    p = &a;     // get pointer address

    cout << &a << endl;     // 0x7ffeef3c7b8c, a的地址
    cout << p << endl;      // 0x7ffeef3c7b8c, p的内容与a地址相同
    cout << &p << endl;     // 0x7ffc73470b10, p的地址与p的内容不同
    cout << sizeof(p) << endl;  // 地址的大小为8bit
    cout << *p << endl;     // 取p指向的地址的内容，即a的内容

    // 空指针
    int *p1 = NULL;             // 无法访问

    // 野指针
    int *p2 = (int *)0x1100;    // 无法访问


    // const 修饰指针
    int a1 = 10;
    int b1 = 10;

    const int * po1 = &a1;  // const 修饰指针，指针指向可以修改，内容无法修改
    po1 = &b1;              // 可以修改指针指向  
    //*po1 = 100;           // 报错， 无法修改指针内容

    int * const po2 = &a1;  // const 修饰常量，指针指向无法修改，内容可以修改
    // po2 = &b1;           // 报错，无法修改指针指向
    *po2 = 100;             // 可以修改指针内容
    cout << a1 << endl;     // 通过指针修改内容之后，指针指向的变量内容同时也发生改变

    const int * const po3 = &a1;    // const 修饰指针和常量，指向和内容都不能修改
    //p3 = &b; //错误
	//*p3 = 100; //错误

    return 0;
}


// 指针与数组
void try_pointer_array()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int * p = arr;

    cout << "First element: " << arr[0] << endl;
    cout << "First element from pointer: " << *p << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << *p << endl;
        p++;
    }
    
}

// 函数传递指针地址，可以修改函数外的实参
void try_pointer_func(int * p1, int * p2)
{   
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}




// 利用指针实现数组中的冒泡排序
// 传入数组的指针，修改数组内容即修改函数外数组的内容
// 为了不修改作为实参的数组，可以使用const修饰符
// void try_bubble_array_pointer(const int * arr, int len);
void try_bubble_array_pointer(int * arr, int len)   // int * arr 也可以写成 int arr[]
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }   
}

void print_array(const int * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    try_pointer();
    try_pointer_array;

    // 传递指针作为参数给函数
    int a = 1;
    int b = 2;
    cout << a << " " << b << endl;
    try_pointer_func(&a, &b);           // 函数参数为指针，可以修改函数外的实参
    cout << a << " " << b << endl;

    // 使用指针和数组实现冒泡排序
    int arr[10] = {2,4,6,1,8,3,7,3,8,9};
    try_bubble_array_pointer(arr, 10);
    print_array(arr, 10);
    


    return 0;
}


