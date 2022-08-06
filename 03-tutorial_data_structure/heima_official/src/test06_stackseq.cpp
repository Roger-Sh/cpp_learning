#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "StackSeq.h"

/**
 * @brief 测试顺序栈 StackSeq
 *
 */

namespace ST_S
{
    typedef struct PERSON
    {
        char name[64];
        int age;
    } Person;

}

void test06_stackseq()
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

/**
 * @brief main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    test06_stackseq();

    return 0;
}
