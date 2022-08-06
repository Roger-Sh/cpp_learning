#ifndef STACKSEQ_H
#define STACKSEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include <string>

namespace ST_S
{

// 数组模拟栈的顺序储存
#define MAX_SIZE 1024
#define STACKSEQ_TRUE 1
#define STACKSEQ_FALSE 0

typedef struct STACKSEQ
{
    void* data[MAX_SIZE];
    int size;
}StackSeq;

// 初始化栈
StackSeq* init_StackSeq();

// 入栈操作
void push_StackSeq(StackSeq* stack, void* data);

// 返回栈顶元素
void* top_StackSeq(StackSeq* stack);

// 出栈栈顶元素
void pop_StackSeq(StackSeq* stack);

// 判断是否为空
int isEmpty_StackSeq(StackSeq* stack);

// 返回元素个数
int getSize_StackSeq(StackSeq* stack);

// 清空栈
void clear_StackSeq(StackSeq* stack);

// 销毁
void freeSpace_StackSeq(StackSeq* stack);





}
#endif