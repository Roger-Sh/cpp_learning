#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "QueueSeq.h"

/**
 * @brief 测试顺序队列 QueueSeq
 * 
 */

namespace QS
{
    typedef struct PERSON
    {
        char name[64];
        int age;
    } Person;

} // namespace QS

void test08_queueseq()
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

/**
 * @brief main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    test08_queueseq();

    return 0;
}
