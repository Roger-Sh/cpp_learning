#ifndef STACKLINK_H
#define STACKLINK_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <string>

namespace ST_L
{

// 链式栈的节点
typedef struct LINKNODE
{
    struct LINKNODE* next;
}LinkNode;

// 链式栈
typedef struct STACKLINK
{
    LinkNode head;
    int size;
}StackLink;


// 初始化
StackLink* init_StackLink();

// 入栈
void push_StackLink(StackLink* stack, LinkNode* data);

// 出栈
void pop_StackLink(StackLink* stack);

// 返回栈顶元素
LinkNode* top_StackLink(StackLink* stack);

// 返回栈元素个数
int getSize_StackLink(StackLink* stack);

// 清空栈
void clear_StackLink(StackLink* stack);

// 销毁栈
void freeSpace_StackLink(StackLink* stack);



}



#endif 