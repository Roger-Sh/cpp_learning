#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "LinkList.h"

/**
 * @brief 测试单向链表
 * 
 */

namespace LL
{

    // 自定义数据结构
    struct Person
    {
        char name[64];
        int age;
        int score;
    };

    // 自定义打印函数
    void MyPrint(void *data)
    {
        Person *p = (Person *)data;

        std::cout << "Name: " << p->name
                  << " Age: " << p->age
                  << " Score: " << p->score
                  << std::endl;
    }

}

void test02_linklist()
{
    // 创建列表
    LL::LinkList *list = LL::init_LinkList();

    LL::Person p1 = {"a1", 18, 100};
    LL::Person p2 = {"a2", 19, 100};
    LL::Person p3 = {"a3", 20, 100};
    LL::Person p4 = {"a4", 21, 100};
    LL::Person p5 = {"a5", 22, 100};

    // 数据插入
    LL::insert_LinkList(list, 0, &p1);
    LL::insert_LinkList(list, 0, &p2);
    LL::insert_LinkList(list, 0, &p3);
    LL::insert_LinkList(list, 0, &p4);
    LL::insert_LinkList(list, 0, &p5);

    // 打印
    LL::print_LinkList(list, LL::MyPrint);

    // 删除
    LL::removeByPos_LinkList(list, 3);

    // 打印
    std::cout << "------------\n";
    LL::print_LinkList(list, LL::MyPrint);

    // 返回第一个节点
    std::cout << "-----return first node-----\n";
    LL::LinkNode *ret = (LL::LinkNode *)LL::getFront_LinkList(list);
    LL::MyPrint(ret->data);

    // 销毁
    LL::freeSpace_LinkList(list);
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
    test02_linklist();
    return 0;
}
