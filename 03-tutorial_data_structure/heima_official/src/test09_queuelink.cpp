#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "QueueLink.h"

/**
 * @brief 测试链式队列  QueueLink
 * 
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

void test09_queuelink()
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

/**
 * @brief main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    test09_queuelink();
    return 0;
}
