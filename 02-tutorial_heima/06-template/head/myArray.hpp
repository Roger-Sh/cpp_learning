#include <iostream>
using namespace std;

// 模板类 MyArray
template<class T>
class MyArray
{
public:
    // 构造函数
    MyArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        pAddress = new T[this->m_capacity];
    }

    // 拷贝构造
    MyArray(const MyArray & arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[this->m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            // 如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
			// 普通类型可以直接= 但是指针类型需要深拷贝
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // 重载 = 操作符， 防止浅拷贝问题
    MyArray& operator=(const MyArray& arr)
    {
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->m_capacity = 0;
            this->m_size = 0;
        }
    
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[this->m_capacity];

        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr[i];
        }
        
        return * this;
    }


    // 重载 [] 操作符 arr[0]
    T& operator[](int index)
    {
        return this->pAddress[index];   // 不考虑越界
    }


    // 尾插法
    void push_back(const T & val)
    {
        // 若超出容量，打断操作
        if (this->m_capacity == this->m_size)
        {
            return;
        }

        this->pAddress[this->m_size] = val;
        this->m_size++;
    }


    // 尾删法
    void pop_back()
    {
        // 若个数为0，打断操作
        if (this->m_size == 0)
        {
            return;
        }

        this->m_size--;
    }


    // 获取数组容量
    int get_capacity()
    {
        return this->m_capacity;
    }


    // 获取当前数组大小
    int get_size()
    {
        return this->m_size;
    }


    // 析构函数
    ~MyArray()
    {
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
    }


private:
    T * pAddress;       // 指向一个堆空间，这个空间储存真正的数据
    int m_capacity;     // 容量
    int m_size;         // 大小

};