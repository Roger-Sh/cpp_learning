#include <iostream>

void test_cin()
{
    // 使用cin输入时要包含头文件iostream
    // 它从标准输入流中读取对应数据类型的数据，并自动判断读入数据是否有效，可用cin.good()或者cin.fail()来判断
    // cin语句执行完后不会舍弃最后一个结束符（tab键、空格键、回车键），它被留在缓冲区。
    // cin会在’空格’、‘Tab’、'回车’处截断

    std::cout << "test_cin: \n";

    std::cout << "Please enter a1 a2 a3: \n";

    int a1, a2;
    std::cin >> a1 >> a2;
    std::cout << a1 << std::endl << a2 << std::endl;

    int a3;
    a3 = std::cin.get();
    std::cout << a3 << std::endl;   // 32, 说明空格被读取到了

    std::cin >> a3;
    std::cout << a3 << std::endl;

    std::cin >> a3;
    std::cout << a3 << std::endl;
}

void test_cin_get_char()
{
    // 头文件 iostream
    // 读取字符
    // 用法1: char ch = std::cin.get()
    // 用法2: std::cin.get(char ch)

    std::cout << "test_cin_get_char: \n";

    char ch;

    while ((ch = std::cin.get()) != EOF)
    {
        std::cout << ch << "\n";

        if (ch == 'q')
        {
            break;
        }
    }
    
    while(std::cin.get(ch))
    {
        std::cout << ch << "\n";

        if (ch == 'q')
        {
            break;
        }

    }
}

void test_cin_getline()
{
    // iostream
    // 读取字符数组
    // 用法1: std::cin.get(字符数组名，长度，结束符)
    // 用法2: std::cin.getline(字符数组名，长度，结束符)
    // 这两个函数都只能对字符数组进行读入
    // 即参数列表第一个必须是字符数组的首地址，也即字符数组名；
    // 这两个函数的长度是包含了尾零'\0'的。
    // 比如cin.get(arr,5,'\n')其实只输入了4个字符，第五个是'\0'。

    // std::cin.getline(...)输入完成之后，后面的所有数据全部被抛弃

    std::cout << "test_cin_get_char_array: \n";
    char b[10];
    std::cin.get(b, 5, '\n');
    std::cout << b << std::endl;

    std::cin.clear();
    std::cin.sync();

    char ch3;
    ch3 = std::cin.get();
    std::cout << ch3 << std::endl;

    char ch4;
    ch4 = std::cin.get();
    std::cout << ch4 << std::endl; 

    // cin.get() 没有读取完的字符会保留, 暂时没找到清空的方法, 不方便使用

    std::cout << "test_cin_getline: \n";
    char a[10];
    std::cin.getline(a, 5, '\n');
    std::cout << a << std::endl;

    char ch1;
    ch1 = std::cin.get();
    std::cout << ch1 << std::endl;

    char ch2;
    ch2 = std::cin.get();
    std::cout << ch2 << std::endl;
}

void test_getline_string()
{
    std::cout << "test_getline_string: \n";

    std::string str;
    while(std::getline(std::cin, str))
    {
        std::cout << str << std::endl;

        try
        {
            int str_int = std::stoi(str);
            std::cout << str_int << std::endl;

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "please enter integer for stoi" << std::endl;
        }


        if (str[0] == 'y')
        {
            std::cout << "yes!" << std::endl;
        }
        else if (str[0] == 'n')
        {
            std::cout << "no!" << std::endl;
        }
        else if (str[0] == 'q')
        {
            std::cout << "quit!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Please enter 'y', 'n' or 'q' \n"; 
        }
    }


}

int main()
{
    // test_cin();
    // test_cin_get_char();
    // test_cin_getline();
    test_getline_string();

    return 0;
}