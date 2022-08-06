#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "LinkList_Double.h"

/**
 * @brief 测试双向链表
 * 
 */

namespace LLD
{
    typedef struct PERSON
    {
        LinkNodeDouble node;
        char name[64];
        int age;
        int score;
    } Person;

    void MyPrint(LinkNodeDouble *data)
    {
        Person *p = (Person *)data;
        std::cout << "Name: " << p->name
                  << " age: " << p->age
                  << " score: " << p->score
                  << std::endl;
    }

    int MyCompare(LinkNodeDouble *data1, LinkNodeDouble *data2)
    {
        Person *p1 = (Person *)data1;
        Person *p2 = (Person *)data2;

        if (strcmp(p1->name, p2->name) == 0 &&
            p1->age == p2->age &&
            p1->score == p2->score)
        {
            return LINKLISTDOUBLE_TRUE;
        }

        return LINKLISTDOUBLE_FALSE;
    }

} // namespace LLD

void test05_linklistdouble()
{
    // 创建双向链表
    LLD::LINKLSTDOUBLE *list = LLD::init_LinkListDouble();

    // 创建数据
    LLD::Person p1, p2, p3, p4, p5, p6, p7, p8, p9;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");
    strcpy(p6.name, "fff");
    strcpy(p7.name, "ggg");
    strcpy(p8.name, "hhh");
    strcpy(p9.name, "iii");
    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;
    p6.age = 60;
    p7.age = 70;
    p8.age = 80;
    p9.age = 90;
    p1.score = 50;
    p2.score = 51;
    p3.score = 52;
    p4.score = 53;
    p5.score = 54;
    p6.score = 55;
    p7.score = 56;
    p8.score = 57;
    p9.score = 58;

    // 插入数据
    LLD::insert_LinkListDouble(list, 100, (LLD::LinkNodeDouble *)&p1);
    LLD::insert_LinkListDouble(list, 100, (LLD::LinkNodeDouble *)&p2);
    LLD::insert_LinkListDouble(list, 100, (LLD::LinkNodeDouble *)&p3);
    LLD::insert_LinkListDouble(list, 100, (LLD::LinkNodeDouble *)&p4);
    LLD::insert_LinkListDouble(list, 100, (LLD::LinkNodeDouble *)&p5);

    LLD::insert_LinkListDouble(list, 5, (LLD::LinkNodeDouble *)&p6);
    LLD::insert_LinkListDouble(list, -6, (LLD::LinkNodeDouble *)&p7);
    LLD::insert_LinkListDouble(list, -1, (LLD::LinkNodeDouble *)&p8);
    LLD::insert_LinkListDouble(list, -100, (LLD::LinkNodeDouble *)&p9);
    // 打印数据
    std::cout << "print front" << std::endl;
    LLD::printFront_LinkListDouble(list, LLD::MyPrint);
    std::cout << "print back" << std::endl;
    LLD::printBack_LinkListDouble(list, LLD::MyPrint);

    // 删除
    LLD::removeByPos_LinkListDouble(list, 8);
    std::cout << "print front" << std::endl;
    LLD::printFront_LinkListDouble(list, LLD::MyPrint);
    LLD::removeByPos_LinkListDouble(list, -8);
    std::cout << "print front" << std::endl;
    LLD::printFront_LinkListDouble(list, LLD::MyPrint);
    LLD::removeByVal_LinkListDouble(list, (LLD::LinkNodeDouble *)&p2, LLD::MyCompare);
    std::cout << "print front" << std::endl;
    LLD::printFront_LinkListDouble(list, LLD::MyPrint);
    LLD::printBack_LinkListDouble(list, LLD::MyPrint);

    // 返回第一个元素
    LLD::MyPrint(LLD::getFront_LinkListDouble(list));
    LLD::MyPrint(LLD::getBack_LinkListDouble(list));

    // 查找
    std::cout << LLD::findFront_LinkListDouble(list, (LLD::LinkNodeDouble *)&p1, LLD::MyCompare) << std::endl;
    std::cout << LLD::findFront_LinkListDouble(list, (LLD::LinkNodeDouble *)&p6, LLD::MyCompare) << std::endl;
    std::cout << LLD::findBack_LinkListDouble(list, (LLD::LinkNodeDouble *)&p1, LLD::MyCompare) << std::endl;
    std::cout << LLD::findBack_LinkListDouble(list, (LLD::LinkNodeDouble *)&p6, LLD::MyCompare) << std::endl;

    // 长度
    std::cout << LLD::getSize_LinkListDouble(list) << std::endl;

    // 判空
    std::cout << LLD::isEmpty_LinkListDouble(list) << std::endl;

    // 销毁队列
    LLD::freeSpace_LinkListDouble(list);
}

/**
 * @brief main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    test05_linklistdouble();

    return 0;
}
