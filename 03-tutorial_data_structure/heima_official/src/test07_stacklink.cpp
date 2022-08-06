#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "StackLink.h"

/**
 * @brief 测试链表栈 StackLink
 * 
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

void test07_stacklink()
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
            若栈顶符号优先级低，此符号进栈 （左括号优先级最低）* / 大于 +- 大于 )(
            若栈顶符号优先级不低，大于等于，将栈顶符号弹出并输出，此符号进栈
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

    // 返回运算符号优先级
    int GetPriority(char *p)
    {
        if (*p == '*' || *p == '/')
        {
            return 2;
        }

        if (*p == '+' || *p == '-')
        {
            return 1;
        }

        return 0;
    }

    // 操作运算符号
    void OperatorOperate(StackLink* stack, char* p)
    {
        // 取出栈顶符号
        ST_L::MyChar* mychar = (ST_L::MyChar*) ST_L::top_StackLink(stack);
        if (mychar == NULL)
        {
            ST_L::push_StackLink(stack, (LinkNode*)CreateMyChar(p));
            return;
        }

        // 如果栈顶优先级低于当前字符优先级， 直接入栈
        if (ST_L::GetPriority(mychar->pAddr) < ST_L::GetPriority(p))
        {
            ST_L::push_StackLink(stack, (LinkNode*)CreateMyChar(p));
            return;
        }

        // 如果栈顶符号优先级不低
        else
        {
            while (ST_L::getSize_StackLink(stack) > 0)
            {
                MyChar* mychar2 = (MyChar*) top_StackLink(stack);

                // 如果优先级低， 当前符号入栈
                if (ST_L::GetPriority(mychar2->pAddr) < ST_L::GetPriority(p))
                {
                    ST_L::push_StackLink(stack, (LinkNode*)CreateMyChar(p));
                    break;
                }

                // 输出
                printf("%c", *(mychar2->pAddr));

                // 弹出
                pop_StackLink(stack);
            
                // 释放
                free(mychar2);
            }   
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

        // 如果是运算符号
        if (ST_L::isOperator(p))
        {
            ST_L::OperatorOperate(stack, p);
        }
        p++;
    }

    while (ST_L::getSize_StackLink(stack) > 0)
    {
        ST_L::MyChar* mychar = (ST_L::MyChar*) ST_L::top_StackLink(stack);
    
        printf("%c", *(mychar->pAddr));

        ST_L::pop_StackLink(stack);
        free(mychar);
    }

    std::cout << std::endl;
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
    test07_stacklink();

    test11_stackApplication_nearMatch();

    test12_stackApplication_ReverseNotation();

    return 0;
}
