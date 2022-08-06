#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "LinkList_Circle.h"

/**
 * @brief 测试循环链表
 * 
 */

namespace CL
{

    typedef struct PERSON
    {
        CircleLinkNode node;
        char name[64];
        int age;
        int score;
    } Person;

    void MyPrint(CircleLinkNode *data)
    {
        Person *p = (Person *)data;
        std::cout << "Name: " << p->name
                  << " age: " << p->age
                  << " score: " << p->score
                  << std::endl;
    }

    int MyCompare(CircleLinkNode *data1, CircleLinkNode *data2)
    {
        Person *p1 = (Person *)data1;
        Person *p2 = (Person *)data2;

        if (strcmp(p1->name, p2->name) == 0 &&
            p1->age == p2->age &&
            p1->score == p2->score)
        {
            return CIRCLELINKLIST_TRUE;
        }

        return CIRCLELINKLIST_FALSE;
    }

} // namespace CL

void test04_circlelinklist()
{
    // 创建循环链表
    CL::CircleLinkList *clist = CL::init_CircleLinkList();

    // 创建数据
    CL::Person p1, p2, p3, p4, p5;
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
    p1.score = 50;
    p2.score = 51;
    p3.score = 52;
    p4.score = 53;
    p5.score = 54;

    // 插入数据
    CL::insert_CircleLinkList(clist, 100, (CL::CircleLinkNode *)&p1);
    CL::insert_CircleLinkList(clist, 100, (CL::CircleLinkNode *)&p2);
    CL::insert_CircleLinkList(clist, 100, (CL::CircleLinkNode *)&p3);
    CL::insert_CircleLinkList(clist, 100, (CL::CircleLinkNode *)&p4);
    CL::insert_CircleLinkList(clist, 100, (CL::CircleLinkNode *)&p5);

    // 打印
    CL::print_CircleLinkList(clist, CL::MyPrint);

    // 删除
    CL::Person pDel;
    strcpy(pDel.name, "ccc");
    pDel.age = 30;
    pDel.score = 52;
    CL::removeByVal_CircleLinkList(clist, (CL::CircleLinkNode *)&pDel, CL::MyCompare);
    std::cout << "--------------------" << std::endl;
    CL::print_CircleLinkList(clist, CL::MyPrint);

    // 释放内存
    CL::freeSpace_CircleLinkList(clist);
}

/*
约瑟夫问题：
循环链表典型应用
N个人围成一个圈，首先第一个人从1开始顺时针报数，
报到第M个人，让其出列，然后再从下一个人开始从1顺时针报数，
报到第M个人，再让其出列，如此重复，求出列顺序
*/

namespace CL
{
#define M 8
#define N 3

    typedef struct MYNUM
    {
        CircleLinkNode node;
        int val;
    } MyNum;

    void NumPrint(CircleLinkNode *data)
    {
        MyNum *num = (MyNum *)data;
        std::cout << "val: " << num->val << " ";
    }

    int NumCompare(CircleLinkNode *data1, CircleLinkNode *data2)
    {
        MyNum *num1 = (MyNum *)data1;
        MyNum *num2 = (MyNum *)data2;

        if (num1->val == num2->val)
        {
            return CIRCLELINKLIST_TRUE;
        }

        return CIRCLELINKLIST_FALSE;
    }

}

void test06_circlelinklist_joseph()
{
    // 创建循环链表
    CL::CircleLinkList *clist = CL::init_CircleLinkList();

    // 链表插入数据
    CL::MyNum num[M];
    for (int i = 0; i < M; i++)
    {
        num[i].val = i + 1;
        CL::insert_CircleLinkList(clist, i, (CL::CircleLinkNode *)&num[i]);
    }

    // 打印
    std::cout << "original sequence: " << std::endl;
    CL::print_CircleLinkList(clist, CL::NumPrint);

    // solve joseph
    std::cout << "joseph sequence by n = 3: " << std::endl;
    int index = 1;
    CL::CircleLinkNode *pCurrent = clist->head.next;
    while (CL::getSize_CircleLinkList(clist) > 1)
    {
        // 如果符合约瑟夫条件
        if (index == N)
        {
            // 打印当前数据
            CL::NumPrint(pCurrent);

            // 缓存删除节点的下一个节点
            CL::CircleLinkNode *pNext = pCurrent->next;

            // 删除当前节点
            CL::removeByVal_CircleLinkList(clist, pCurrent, CL::NumCompare);

            // 移动到下一节点，并判断是否为头节点
            pCurrent = pNext;
            if (pCurrent == &(clist->head))
            {
                pCurrent = clist->head.next;
            }

            // 重置 index
            index = 1;
        }

        // 移动到下一节点，并判断是否为头节点
        pCurrent = pCurrent->next;
        if (pCurrent == &(clist->head))
        {
            pCurrent = clist->head.next;
        }

        index++;
    }

    if (CL::getSize_CircleLinkList(clist) == 1)
    {
        CL::CircleLinkNode *tempNode = CL::getFront_CircleLinkList(clist);
        CL::NumPrint(tempNode);
    }
    else
    {
        std::cout << "Joseph is wrong!" << std::endl;
    }

    // 释放内存
    CL::freeSpace_CircleLinkList(clist);
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
    test04_circlelinklist();

    test06_circlelinklist_joseph();
    
    return 0;
}
