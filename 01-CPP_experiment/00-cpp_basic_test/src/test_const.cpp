#include <iostream>
#include <string>

void test01()
{
    /**
     * @brief 针对普通变量
     *
     */

    // 定义时需要初始化
    const int a = 5;
    const std::string name = "xiaoming";

    // 只读，不可改动
    // a = 10;             // error
    // name = "xiaowang";  // error

    /**
     * @brief 针对指针
     * 技巧：const 优先修饰其左侧量，如果左侧没有，则修饰右侧的量
     *      const int *，修饰 int，int 值不能更改，* 指针可以更改
     *      int const *，修饰 int，int 值不能更改，* 指针可以更改
     *      int * const，修饰 *，* 指针不能更改，int 值可以更改
     */

    // 内容 const 方式1，使用 cont int*，指针可以修改，内容不可以修改，不需要初始化
    int a2 = 5;
    const int *c;
    c = &a2;                  // 合法：cont int*，指针可以修改
    std::cout << c << "\n";   // 0x7ffc6bb44220
    std::cout << *c << "\n";  // 5
    a2 = 6;                   // 合法，通过修改指针对应原地址的值，修改内容
    std::cout << c << "\n";   // 0x7ffc6bb44220
    std::cout << *c << "\n";  // 6
    int a3 = 7;
    c = &a3;                  // 合法：cont int*，指针可以修改
    std::cout << c << "\n";   // 0x7ffc6bb44224
    std::cout << *c << "\n";  // 7
    // *c = 8;                // 非法：cont int*，指针可以修改，内容不可以修改

    // 内容 const 方式2
    int const *f;
    int e = 1000;
    f = &e;                   // 合法：指针可以修改
    std::cout << f << "\n";   // 0x7fff0b9e9508
    std::cout << *f << "\n";  // 1000
    // *f = 1001;             // 非法：内容不可以修改
    e = 1001;                 // 合法，通过修改原变量的值，修改当前指针指向的值
    std::cout << f << "\n";   // 0x7fff0b9e9508
    std::cout << *f << "\n";  // 1001
    int e2 = 1002;
    f = &e2;                  // 合法：指针可以修改
    std::cout << f << "\n";   // 0x7fff0b9e950c
    std::cout << *f << "\n";  // 1002

    // 指针 const，使用 int *const, 指针不能修改，内容可以修改，需要初始化
    int b = 100;
    int *const d = &b;        // 创建时需要初始化
    std::cout << d << "\n";   // 0x7ffc6b6bd294
    std::cout << *d << "\n";  // 100
    int b2 = 200;
    // d = &b2;               // 非法：int *const，不能修改指针
    *d = 101;                 // 合法：int *const，可以修改内容
    std::cout << d << "\n";   // 0x7ffc6b6bd294
    std::cout << *d << "\n";  // 101

    // 指针与内容 const，指针和内容都不能修改，需要初始化
    int h = 10000;
    const int *const g = &h;
    std::cout << g << "\n";   // 0x7ffe4d21e3e4
    std::cout << *g << "\n";  // 10000
    int h2 = 20000;
    // g = &h2;               // 非法：指针不能修改
    // *g = 20001;            // 非法：内容不能修改
    h = 10001;                // 合法：通过修改原变量的值来修改当前指针指向的值
    std::cout << g << "\n";   // 0x7ffe4d21e3e4
    std::cout << *g << "\n";  // 10001
}

int main()
{
    test01();

    return 0;
}