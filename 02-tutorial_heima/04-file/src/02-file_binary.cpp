#include <iostream>
using namespace std;


#include <fstream>
#include <string>




/*
以二进制的方式对文件进行读写操作
打开方式要指定为 ==ios::binary==
二进制方式写文件主要利用流对象调用成员函数write
函数原型 ：`ostream& write(const char * buffer,int len);`
参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

*/

class Person
{
public:
    char m_Name[64];
    int m_Age;
};


// 写入二进制文件
void test01()
{
    // 创建输出流对象
    ofstream ofs("../person.txt", ios::out | ios::binary);

    // 打开文件
    // ofs.open("person.txt", ios::out | ios::binary)

    // 实例化 Person 类
    Person p = {"Zhang san", 18};

    // 写入文件
    // 函数原型 ostream& write(const char * buffer,int len);
    ofs.write((const char *)&p, sizeof(p));

    // 关闭输出流对象
    ofs.close();
}


// 读取二进制文件
void test02()
{
    ifstream ifs("../person.txt", ios::in | ios::binary);

    if (!ifs.is_open())
    {
        cout << "file open failed" << endl;
    }

    Person p;

    ifs.read((char *)&p, sizeof(p));

    cout << "Name: " << p.m_Name << " Age: " << p.m_Age << endl;

}

int main()
{
    test01();
    test02();


    return 0;
}