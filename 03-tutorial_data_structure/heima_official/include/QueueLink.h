#ifndef QUEUELINK_H
#define QUEUELINK_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <string>

namespace QL
{

// 链式队列的节点
typedef struct LINKNODE
{
    struct LINKNODE* next;
}LinkNode;


// 链式队列
typedef struct QUEUELINK
{
    LinkNode head;
    LinkNode* rear;
    int size;
}QueueLink;

// 初始化
QueueLink* init_QueueLink();

// 入队列
void push_QueueLink(QueueLink* queue, LinkNode* data);

// 出队列
void pop_QueueLink(QueueLink* queue);

// 返回队头元素
LinkNode* front_QueueLink(QueueLink* queue);

// 返回队尾元素
LinkNode* back_QueueLink(QueueLink* queue);

// 返回队列元素个数
int getSize_QueueLink(QueueLink* queue);

// 清空队列元素
void clear_QueueLink(QueueLink* queue);

// 销毁队列
void freeSpace_QueueLink(QueueLink* queue);

} // namespace QL


#endif // QUEUELINK_H