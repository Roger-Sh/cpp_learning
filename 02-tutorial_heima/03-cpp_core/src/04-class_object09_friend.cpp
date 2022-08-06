#include <iostream>

using namespace std;

/*
生活中你的家有客厅(Public)，有你的卧室(Private)
客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去
但是呢，你也可以允许你的好闺蜜好基友进去。
在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
友元的目的就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为  ==friend==

友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元

*/


class Building;


// 友元成员函数, 必须先声明，最后再定义具体内容，因为此时Building类还未实现
class NiceGuy
{

public:
    // constructor
    NiceGuy();

    // friend to class Building
    void visit_day();

    // not friend to class Building
    void visit_night();


private:
    Building *building;

};



/*
使用友元来访问Building类中的私有内容
*/

// 全局函数做友元
class Building
{
    // goodGuy全局函数 是 Building类的好朋友，可以访问类中的私有内容
    friend void goodGuy(Building * building);

    // GoodGuy类是 Building类的好朋友，可以访问类中的私有内容
    friend class GoodGuy;

    // NiceGuy类中 visit_day成员函数是Building好朋友，可以访问私有内容
    friend void NiceGuy::visit_day();

public:

    // 构造器
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom;   // 客厅

private:
    string m_BedRoom;       // 卧室

};



// 友元函数
void goodGuy(Building * building)
{
    cout << "Good guy is visiting: " << building->m_SittingRoom << endl;
    cout << "Good guy is visiting: " << building->m_BedRoom << endl;
}


void test01()
{
    Building b;
    goodGuy(&b);
}


// 友元类
class GoodGuy
{
public:
    // constructor
    GoodGuy()
    {
        building = new Building;
    };
    
    void visit()
    {
        cout << "GoodGuy is visiting " << building->m_SittingRoom << endl;
        cout << "GoodGuy is visiting " << building->m_BedRoom << endl;
    };

private:
    Building *building;

};

void test02()
{
    GoodGuy gg;
    gg.visit();
}





// 友元成员函数

// constructor
NiceGuy::NiceGuy()
{
    building = new Building;
};

// 可以访问Building私有内容的友元成员函数
void NiceGuy::visit_day()
{
    cout << "Nice guy is visiting " << building->m_SittingRoom << " during the day." << endl;
    cout << "Nice guy is visiting " << building->m_BedRoom << "during the day." << endl;
};

// 无法访问Building私有内容的成员函数，因为它不是Building的友元函数
void NiceGuy::visit_night()
{
    cout << "Nice guy is visiting " << building->m_SittingRoom << " at night." << endl;
    // cout << "Nice guy is visiting " << building->m_BedRoom << "at night." << endl;
};





int main()
{
    test01();
    test02();


    return 0;
}