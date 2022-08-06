#include <iostream>
#include <fstream>          // 读写操作



using namespace std;

/*
程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过**文件可以将数据持久化**

C++中对文件操作需要包含头文件 ==&lt; fstream &gt;==



文件类型分为两种：

1. **文本文件**     -  文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件** -  文件以文本的**二进制**形式存储在计算机中，用户一般不能直接读懂它们



操作文件的三大类:

1. ofstream：写操作
2. ifstream： 读操作
3. fstream ： 读写操作

| ios::in     | 为读文件而打开文件         
| ios::out    | 为写文件而打开文件         
| ios::ate    | 初始位置：文件尾          
| ios::app    | 追加方式写文件           
| ios::trunc  | 如果文件存在先删除，再创建   
| ios::binary | 二进制方式                

*/

// 写入操作
void test01()
{
    ofstream ofs;
    ofs.open("../test.txt", ios::out);  // (ios::out | ios::in)

    ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

    ofs.close();
}

// 读取操作
void test02()
{
    ifstream ifs;
    ifs.open("../test.txt", ios::in);

    // 判断是否读取正确
    if (!ifs.is_open())
    {
        cout << "file open failed" << endl;
        return;
    }

    // 读取方式1 通过 >> 赋值给buf字符数组
    // char buf[1024] = { 0 };
    // int i = 0;
    // while (ifs >> buf)
    // {
    //     cout << buf << " 行数: " << i << endl;
    //     i++;
    // }

    // 读取方式2 通过 getline() 赋值给字符数组
    // char buf[1024] = { 0 };
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    
    // 读取方式3 通过 getline() 赋值给string
    // string buf;
    // while(getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }

    // 读取方式4 通过get()
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c ;     // << endl; 这个实现是逐步读取字符,所以不能加换行符,因为如果这样的话中文会乱码
    }

    ifs.close();

}


int main()
{

    test01();
    test02();

    return 0;
}