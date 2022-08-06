#include <iostream>

using namespace std;

/*
关系运算符重载

**作用：**重载关系运算符，可以让两个自定义类型对象进行对比操作


*/


class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    };


    // 关系运算符重载
    bool operator==(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool operator>=(Person &p)
    {
        if(this->m_Age >= p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


private:
    string m_Name;
    int m_Age;
};



void test01()
{
    Person a("Goku", 18);
    Person b("Goku", 18);
    Person c("Yamucha", 20);

    if (a == b)
	{
		cout << "a和b相等" << endl;
	}
	else
	{
		cout << "a和b不相等" << endl;
	}

	if (a != b)
	{
		cout << "a和b不相等" << endl;
	}
	else
	{
		cout << "a和b相等" << endl;
	}

    if(a >= c)
    {
        cout << "a大于等于c" << endl; 
    }
    else
    {
        cout << "a小于c" << endl;
    }

}



int main()
{
    test01();
    return 0;
}