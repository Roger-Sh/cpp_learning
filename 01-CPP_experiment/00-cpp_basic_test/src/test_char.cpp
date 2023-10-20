#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

void test01()
{
    /**
     * @brief 测试 char
     *
     */
    char ch = 'a';
    std::cout << ch << "\n";                        // a
    std::cout << &ch << "\n";                       // 取地址符，a@+{t� 乱码
    std::cout << static_cast<void *>(&ch) << "\n";  // 0x7ffe3e37d577
    // std::cout << *ch << "\n";                    // 非法：error, invalid type argument of unary ‘*’ (have ‘char’)

    /**
     * @brief 测试 char *
     * 1.声明了一个char*的标量，也就是声明了一个指向char的指针。
     * 2.在内存的文字常量区，开辟了一个空间存储字符串常量"c1"。
     * 3.返回这个区域的地址，并且这个地址作为值给了字符指针变量a。
     * 最终的结果就是：指针变量a指向了一个字符串常量"c1"。因为”c1“是在常量区，所以其内容是不可以修改的。
     */
    char *ch2;
    ch2 = "abc";                                    // 非法：c++ 禁用，但是可行，把首字符的地址赋值给了 ch2
    std::cout << ch2 << "\n";                       // abc
    std::cout << &ch2 << "\n";                      // 0x7ffee978df30
    std::cout << static_cast<void *>(ch2) << "\n";  // 0x555a784e2d87
    // *ch2 = 'e';                                  // 非法：segmentation fault, 正在修改常量区的内容，
    ch2 = "def";               // 合法：可以修改整个字符串常量
    std::cout << ch2 << "\n";  // def

    char *ch3 = "abcdefgh";              // 非法：c++ 禁用，但是可行，把首字符的地址赋值给了 ch3
    std::cout << ch3 << "\n";            // abcdefgh
    ch3 = "efg";                         // 重新赋予了常量区的字符串的首字符地址
    std::cout << ch3 << "\n";            // efg
    std::cout << sizeof(ch3) << "\n";    // 8, 表示 char* 的长度
    std::cout << strlen(ch3) << "\n";    // 3, 表示3个字符长度
    std::cout << sizeof("efg") << "\n";  // 4，"efg\0" 4个字符，包括结束符 \0
    std::cout << *(ch3 + 0) << "\n";     // e
    std::cout << *(ch3 + 1) << "\n";     // f
    std::cout << *(ch3 + 2) << "\n";     // g
    std::cout << *(ch3 + 3) << "\n";     // 结束符 \0， 不会显示

    char *ch4 = {"hello"};          // 非法：c++ 禁用，但是可行，把首字符的地址赋值给了 ch3
    std::cout << ch4 << std::endl;  // hello
    // ch4[0] = 'H';                // 非法：segmentation fault，其内容在常量区，无法被修改

    /**
     * @brief 测试 char[]
     *
     */
    char ch5[6] = "hello";        // 实际长度为6，"hello\0"
    std::cout << ch5 << "\n";     // hello
    std::cout << ch5[0] << "\n";  // h
    std::cout << ch5[5] << "\n";  // 结束符 \0， 不会显示
    ch5[0] = 'H';                 // 合法：可以修改指针对应的内容
    ch5[1] = 'E';
    ch5[2] = 'L';
    ch5[3] = 'L';
    ch5[4] = 'O';
    std::cout << ch5 << "\n";  // HELLO

    char ch6[] = {"hello2"};                // 可以不指定长度，自动开辟内存大小
    std::cout << strlen(ch6) << std::endl;  // 6
    std::cout << sizeof(ch6) << std::endl;  // 7 with \0
    ch6[0] = 'H';                           // 合法：数组里面的内容是可以修改
    // ch6 = "hello3";                      // 非法：表达式必须是可修改的左值，数组地址是不能发生变化
    std::cout << ch6 << "\n";

    /**
     * @brief 推荐的 char* 与 char[] 赋值方法
     *
     */

    const char *str = "hello world";
    std::cout << str << "\n";

    char str2[] = "hello world2";
    std::cout << str2 << "\n";

    /**
     * @brief 测试 strcpy
     *
     */

    // 没有const修饰
    char *homework = new char[10];
    std::cout << "static_cast<void *>(homework): " << static_cast<void *>(homework) << "\n";  // 0x5652ccb55280
    strcpy(homework, "math");
    std::cout << "static_cast<void *>(homework): " << static_cast<void *>(homework) << "\n";  // 0x5652ccb55280
    std::cout << "homework: " << homework << "\n";                                            // homework: math

    // const 修饰 指针，strcpy 只能赋值第一个字符
    char *const homework2 = new char[10];
    std::cout << "static_cast<void *>(homework2): " << static_cast<void *>(homework2) << "\n";  // 0x556e61cb72a0
    strcpy(homework2, "english");
    std::cout << "static_cast<void *>(homework2): " << static_cast<void *>(homework2) << "\n";  // 0x556e61cb72a0
    std::cout << "homework2: " << *homework2 << "\n";                                           // homework2: e

    const char *homework3 = new char[10];
    std::cout << "static_cast<const void *>(homework3): " << static_cast<const void *>(homework3) << "\n";  // 0x55d72074c2c0
    // strcpy(homework3, "english"); // const 修饰 char 内容无法被修改
    std::cout << "homework3: " << *homework3 << "\n";  // homework3:

    /**
     * @brief 总结
        1.char *p = "hello"，p指针指向的值是可以变化的，但是p只能指向（字符串）常量，并且其指向的内存范围里内容不能发生改变。规范写法为const char
        *p或者char const *p，p为一个常量指针。
        2.char a[]这种写法，a的内存地址即指向不能变，但是内存里的内容能发生变化，等同于char *const a，为一个指针常量。
        3.const在*前：表示const修饰的为所申明的类型，为常量指针
        4.const在*后：表示const修饰的为指针，为指针常量
     */
}

/**
 * @brief 测试 char, char*, char[]
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
