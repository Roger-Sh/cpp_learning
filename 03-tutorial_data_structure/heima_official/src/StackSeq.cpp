#include "StackSeq.h"

namespace ST_S
{

// 初始化栈
StackSeq* init_StackSeq()
{
    StackSeq* stack = (StackSeq*)malloc(sizeof(StackSeq));
    
    for(int i = 0; i < MAX_SIZE; i++)
    {
        stack->data[i] = NULL;
    }
    stack->size = 0;

    return stack;
}


// 入栈操作
void push_StackSeq(StackSeq* stack, void* data)
{
    // check stack
    if(stack == NULL)
    {
        return;
    }

    // check data
    if(data == NULL)
    {
        return;
    }

    // check size
    if(stack->size == MAX_SIZE)
    {
        return;
    }

    // push
    stack->data[stack->size] = data;
    stack->size++;

}

// 返回栈顶元素
void* top_StackSeq(StackSeq* stack)
{
    // check stack
    if(stack == NULL)
    {
        return NULL; 
    }

    // check size
    if(stack->size == 0)
    {
        return NULL;
    }

    return stack->data[stack->size-1];
}


// 出栈栈顶元素
void pop_StackSeq(StackSeq* stack)
{
    // check stack
    if(stack == NULL)
    {
        return; 
    }

    // check size
    if(stack->size == 0)
    {
        return;
    }

    stack->data[stack->size-1] = NULL;
    stack->size--;
}


// 判断是否为空
int isEmpty_StackSeq(StackSeq* stack)
{
    // check stack
    if(stack == NULL)
    {
        return -1; 
    }

    if(stack->size == 0)
    {
        return STACKSEQ_TRUE;
    } 

    return STACKSEQ_FALSE;
}


// 返回元素个数
int getSize_StackSeq(StackSeq* stack)
{
    return stack->size;
}


// 清空栈
void clear_StackSeq(StackSeq* stack)
{
    // check stack
    if(stack == NULL)
    {
        return; 
    }

    for(int i = 0; i < stack->size; i++)
    {
        stack->data[i] = NULL;
    }

    stack->size = 0;
}

// 销毁
void freeSpace_StackSeq(StackSeq* stack)
{
    // check stack
    if(stack == NULL)
    {
        return; 
    }

    free(stack);
}

}