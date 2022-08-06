#ifndef QUEUESEQ_H
#define QUEUESEQ_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <string>

namespace QS
{
#define MAX_SIZE 1024

// 顺序队列 结构体
typedef struct QUEUESEQ
{
    void* data[MAX_SIZE];
    int size;
}QueueSeq;


// 初始化
QueueSeq* init_QueueSeq();

// 入队
void push_QueueSeq(QueueSeq* queue, void* data);

// 出队
void pop_QueueSeq(QueueSeq* queue);

// 返回队头元素
void* front_QueueSeq(QueueSeq* queue);

// 返回队尾元素
void* back_QueueSeq(QueueSeq* queue);

// 返回大小
int getSize_QueueSeq(QueueSeq* queue);

// 清空
void clear_QueueSeq(QueueSeq* queue);

// 销毁
void freeSpace_QueueSeq(QueueSeq* queue);

}



#endif