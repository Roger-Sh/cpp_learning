#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "DynamicArray.h"
#include "LinkList.h"
#include "LinkList_linux.h"
#include "LinkList_Circle.h"
#include "LinkList_Double.h"
#include "StackSeq.h"
#include "StackLink.h"
#include "QueueSeq.h"
#include "QueueLink.h"



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

/*
测试企业链表
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

void test03_linklist_linux()
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

/*
测试循环链表
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
测试双向链表
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

/*
测试顺序栈 StackSeq
*/
namespace ST_S
{
    typedef struct PERSON
    {
        char name[64];
        int age;
    } Person;

}

void test07_stackseq()
{
    // 创建栈
    ST_S::StackSeq *stack = ST_S::init_StackSeq();

    ST_S::Person p1 = {"aaa", 10};
    ST_S::Person p2 = {"bbb", 20};
    ST_S::Person p3 = {"ccc", 30};
    ST_S::Person p4 = {"ddd", 40};
    ST_S::Person p5 = {"eee", 50};

    // 入栈
    ST_S::push_StackSeq(stack, &p1);
    ST_S::push_StackSeq(stack, &p2);
    ST_S::push_StackSeq(stack, &p3);
    ST_S::push_StackSeq(stack, &p4);
    ST_S::push_StackSeq(stack, &p5);

    // 输出
    while (ST_S::getSize_StackSeq(stack) > 0)
    {
        // 访问栈顶元素
        ST_S::Person *person = (ST_S::Person *)ST_S::top_StackSeq(stack);

        std::cout << "Name: " << person->name
                  << " age: " << person->age
                  << std::endl;

        // 弹出栈顶元素
        ST_S::pop_StackSeq(stack);
    }

    // 释放内存
    ST_S::freeSpace_StackSeq(stack);
}

/*
测试链表栈 StackLink
*/
namespace ST_L
{
    typedef struct PERSON
    {
        LinkNode node;
        char name[64];
        int age;
    } Person;

}

void test08_stacklink()
{
    // 创建链式栈
    ST_L::StackLink *stack = ST_L::init_StackLink();

    // 创建数据
    ST_L::Person p1, p2, p3, p4, p5;
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

    // 入栈
    ST_L::push_StackLink(stack, (ST_L::LinkNode *)&p1);
    ST_L::push_StackLink(stack, (ST_L::LinkNode *)&p2);
    ST_L::push_StackLink(stack, (ST_L::LinkNode *)&p3);
    ST_L::push_StackLink(stack, (ST_L::LinkNode *)&p4);
    ST_L::push_StackLink(stack, (ST_L::LinkNode *)&p5);

    // 输出
    while (ST_L::getSize_StackLink(stack) > 0)
    {
        ST_L::Person *person = (ST_L::Person *)ST_L::top_StackLink(stack);
        std::cout << "name: " << person->name
                  << " age: " << person->age
                  << std::endl;
        ST_L::pop_StackLink(stack);
    }

    // 释放内存
    ST_L::freeSpace_StackLink(stack);
}

/*
测试顺序队列 QueueSeq
*/
namespace QS
{
    typedef struct PERSON
    {
        char name[64];
        int age;
    } Person;

} // namespace QS

void test09_queueseq()
{
    // 创建队列
    QS::QueueSeq *queue = QS::init_QueueSeq();

    // 创建数据
    QS::Person p1 = {"aaa", 10};
    QS::Person p2 = {"bbb", 10};
    QS::Person p3 = {"ccc", 10};
    QS::Person p4 = {"ddd", 10};
    QS::Person p5 = {"eee", 10};

    // 入队
    QS::push_QueueSeq(queue, &p1);
    QS::push_QueueSeq(queue, &p2);
    QS::push_QueueSeq(queue, &p3);
    QS::push_QueueSeq(queue, &p4);
    QS::push_QueueSeq(queue, &p5);

    // 输出队尾元素
    QS::Person *pBack = (QS::Person *)QS::back_QueueSeq(queue);
    std::cout << "Name: " << pBack->name
              << " age: " << pBack->age
              << std::endl;

    // 输出
    while (QS::getSize_QueueSeq(queue) > 0)
    {
        // 取出队头元素
        QS::Person *pFront = (QS::Person *)QS::front_QueueSeq(queue);
        std::cout << "Name: " << pFront->name
                  << " age: " << pFront->age
                  << std::endl;

        // 弹出元素
        QS::pop_QueueSeq(queue);
    }

    // 销毁队列
    QS::freeSpace_QueueSeq(queue);
}

/*
测试链式队列  QueueLink
*/
namespace QL
{

    typedef struct PERSON
    {
        QL::LinkNode node;
        char name[64];
        int age;
    } Person;

} // namespace QL

void test10_queuelink()
{
    // 创建链式队列
    QL::QueueLink *queue = QL::init_QueueLink();

    // 创建数据
    QL::Person p1, p2, p3, p4, p5;
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

    // 入队列
    QL::push_QueueLink(queue, (QL::LinkNode *)&p1);
    QL::push_QueueLink(queue, (QL::LinkNode *)&p2);
    QL::push_QueueLink(queue, (QL::LinkNode *)&p3);
    QL::push_QueueLink(queue, (QL::LinkNode *)&p4);
    QL::push_QueueLink(queue, (QL::LinkNode *)&p5);

    // 输出队尾元素
    QL::Person *pBack = (QL::Person *)QL::back_QueueLink(queue);
    std::cout << "Name: " << pBack->name
              << " age: " << pBack->age
              << std::endl;

    // 输出队头元素
    while (QL::getSize_QueueLink(queue) > 0)
    {
        QL::Person *pFront = (QL::Person *)QL::front_QueueLink(queue);
        std::cout << "Name: " << pFront->name
                  << " age: " << pFront->age
                  << std::endl;

        // 弹出元素
        QL::pop_QueueLink(queue);
    }

    // 销毁队列
    QL::freeSpace_QueueLink(queue);
}

/*
栈的应用：就近匹配
扫描字符串，碰到左括号直接入栈，
碰到右括号，从栈顶弹出括号判断是否是左括号，如果是则匹配成功，如果不是则说明匹配失败
*/
namespace ST_L
{
    typedef struct MYCHAR
    {
        LinkNode node;
        char *pAddr;
        int index;
    } MyChar;

    int isLeftBracket(char *c)
    {
        return *c == '(';
    }

    int isRightBracket(char *c)
    {
        return *c == ')';
    }

    MyChar *createMyChar(char *p, int index)
    {
        MyChar *mychar = (MyChar *)malloc(sizeof(MyChar));
        mychar->pAddr = p;
        mychar->index = index;

        return mychar;
    }

} // ST_L

void test11_stackApplication_nearMatch()
{
    // string data with ()
    // char* str = "1+2+6(dsf)dfsf1p((sdfs)";
    char *str = (char *)"y9(((((9)";

    // init stack
    ST_L::StackLink *stack = ST_L::init_StackLink();

    // loop for matching ()
    char *p = str;
    int flag = 1;
    int index = 0;
    while (*p != '\0')
    {
        // check (
        if (ST_L::isLeftBracket(p))
        {
            ST_L::push_StackLink(stack, (ST_L::LinkNode *)ST_L::createMyChar(p, index));
        }

        // check )
        if (ST_L::isRightBracket(p))
        {
            if (ST_L::getSize_StackLink(stack) > 0)
            {
                ST_L::MyChar *mychar = (ST_L::MyChar *)ST_L::top_StackLink(stack);

                if (ST_L::isLeftBracket(mychar->pAddr))
                {
                    ST_L::pop_StackLink(stack);
                    free(mychar);
                }
                else
                {
                    std::cout << "wrong match!" << std::endl;
                    std::cout << "right bracket with index " << index << " has no matched left bracket!" << std::endl;
                    flag = 0;
                    break;
                }
            }
            else
            {
                std::cout << "wrong match!" << std::endl;
                std::cout << "right bracket with index " << index << " has no matched left bracket!" << std::endl;

                flag = 0;
                break;
            }
        }

        p++;
        index++;
    }
    std::cout << "\n";

    // check remaining (
    if (ST_L::getSize_StackLink(stack) > 0)
    {
        std::cout << "wrong match!" << std::endl;
        flag = 0;
        while (ST_L::getSize_StackLink(stack) > 0)
        {
            ST_L::MyChar *mychar = (ST_L::MyChar *)ST_L::top_StackLink(stack);
            std::cout << "Left bracket with index " << mychar->index << " has no matched right bracket!" << std::endl;
            ST_L::pop_StackLink(stack);
            free(mychar);
        }
    }

    if (flag == 1)
    {
        std::cout << "right match!" << std::endl;
    }
}

/*
栈的应用：中缀表达式转后缀表达式

例子：
5 + 4 => 5 4 +
1 + 2 * 3 => 1 2 3 * +
8 + (3 - 1) * 5 => 8 3 1 - 5 * +

中缀转后缀算法：
遍历中缀表达式的数字和符号：
    对于数字，直接输出
    对于符号：
        左括号：进栈
        运算符号：与栈顶符号进行优先级比较
            若栈顶符号优先级低，此符号进栈 （左括号优先级最低）* / > +- > )(
            若栈顶符号优先级不低，将栈顶符号弹出并输出，此符号进栈
        右括号：将栈顶符号弹出并输出，直到匹配左括号
遍历结束，将栈中所有符号弹出并输出
*/

namespace ST_L
{
    // 判断是否是数字
    int IsNumber(char *c)
    {
        return *c >= '0' && *c <= '9';
    }

    // 判断是否是左括号
    int isLeft(char *c)
    {
        return *c == '(';
    }

    // 判断是否是右括号
    int isRight(char *c)
    {
        return *c == ')';
    }

    // 判断是否是运算符
    int isOperator(char *c)
    {
        return *c == '+' || *c == '-' || *c == '*' || *c == '/';
    }

    // 操作数字
    void NumberOperate(char *c)
    {
        printf("%c", *c);
    }

    MyChar* CreateMyChar(char* p)
    {
        MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
        mychar->pAddr = p;
        return mychar;
    }

    // 操作左括号
    void LeftOperate(StackLink* stack, char *p)
    {
        push_StackLink(stack, (LinkNode*)CreateMyChar(p));  
    }

    // 操作右括号
    void RightOperate(StackLink* stack, char *p)
    {
        // 如果栈不为空
        while(ST_L::getSize_StackLink(stack) > 0)
        {
            // 弹出栈顶符号
            ST_L::MyChar* mychar = (ST_L::MyChar*)ST_L::top_StackLink(stack);
            
            // 如果遇到左括号
            if (ST_L::isLeft((mychar->pAddr)))
            {
                ST_L::pop_StackLink(stack);
                break;
            }

            // 输出
            printf("%c", *(mychar->pAddr));

            // 弹出
            ST_L::pop_StackLink(stack);

            // 释放内存
            free(mychar);
        }
    }
}

void test12_stackApplication_ReverseNotation()
{
    char *str = (char *)"8+(3-1)*5";
    char *p = str;

    // 创建栈
    ST_L::StackLink* stack = ST_L::init_StackLink(); 

    while (*p != '\0')
    {
        // 如果是数字，直接打印
        if (ST_L::IsNumber(p))
        {
            ST_L::NumberOperate(p);
        }

        // 如果左括号，直接进栈
        if (ST_L::isLeft(p))
        {
            ST_L::LeftOperate(stack, p);
        }

        // 如果右括号，将栈顶符号弹出，直到遇到左括号
        if(ST_L::isRight(p))
        {
            ST_L::RightOperate(stack, p);
        }



        p++;
    }
}

int main()
{
    // std::cout << "\n\ntest dynamic array" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test01_dynamic_array();

    // std::cout << "\n\ntest link list" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test02_linklist();

    // std::cout << "\n\ntest link list linux" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test03_linklist_linux();

    // std::cout << "\n\ntest circle link list" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test04_circlelinklist();

    // std::cout << "\n\ntest linklistdouble" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test05_linklistdouble();

    // std::cout << "\n\ntest circle link list Joseph problem" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test06_circlelinklist_joseph();

    // std::cout << "\n\ntest stack_seq" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test07_stackseq();

    // std::cout << "\n\ntest stack_link" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test08_stacklink();

    // std::cout << "\n\ntest queue_seq" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test09_queueseq();

    // std::cout << "\n\ntest queue_link" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test10_queuelink();

    // std::cout << "\n\ntest stacklink application: near match" << std::endl;
    // std::cout << "--------------------" << std::endl;
    // test11_stackApplication_nearMatch();

    std::cout << "\n\ntest stacklink application: reverse notation" << std::endl;
    std::cout << "--------------------" << std::endl;
    test12_stackApplication_ReverseNotation();

    return 0;
}