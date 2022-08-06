#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "LinkList_Enterprise.h"

/**
 * @brief 测试企业链表
 * 
 */

namespace LLL
{
    // 自定义数据节点
    typedef struct PERSON
    {
        LLL::LinkNode node;
        char name[64];
        int age;

    } Person;

    // 自定义打印函数
    void MyPrint(LLL::LinkNode *data)
    {
        Person *p = (Person *)data;
        std::cout << "Name: " << p->name
                  << " age: " << p->age
                  << std::endl;
    }

    // 自定义比较函数
    int MyCompare(LLL::LinkNode *node1, LLL::LinkNode *node2)
    {
        Person *p1 = (Person *)node1;
        Person *p2 = (Person *)node2;

        if (strcmp(p1->name, p2->name) == 0 &&
            p1->age == p2->age)
        {
            return 0;
        }

        return -1;
    }

}

void test03_linklist_enterprise()
{
    //创建链表
    LLL::LinkList *list = LLL::init_LinkList();

    // 创建数据
    LLL::Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;

    // 将节点插入链表
    LLL::insert_LinkList(list, 0, (LLL::LinkNode *)&p1);
    LLL::insert_LinkList(list, 0, (LLL::LinkNode *)&p2);
    LLL::insert_LinkList(list, 0, (LLL::LinkNode *)&p3);
    LLL::insert_LinkList(list, 0, (LLL::LinkNode *)&p4);
    LLL::insert_LinkList(list, 0, (LLL::LinkNode *)&p5);

    // 打印
    LLL::print_LinkList(list, LLL::MyPrint);

    // 删除节点
    LLL::remove_LinkList(list, 2);

    // 打印
    std::cout << "--------------------" << std::endl;
    LLL::print_LinkList(list, LLL::MyPrint);

    // 查找
    LLL::Person findP1;
    strcpy(findP1.name, "ccc");
    findP1.age = 30;
    int pos1 = LLL::find_LinkList(list, (LLL::LinkNode *)&findP1, LLL::MyCompare);
    std::cout << "Pos: " << pos1 << std::endl;

    // 查找
    LLL::Person findP2;
    strcpy(findP2.name, "aaa");
    findP2.age = 10;
    int pos2 = LLL::find_LinkList(list, (LLL::LinkNode *)&findP2, LLL::MyCompare);
    std::cout << "Pos: " << pos2 << std::endl;

    // 释放链表内存
    LLL::freeSpace_LinkList(list);
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
    test03_linklist_enterprise();
    return 0;
}
