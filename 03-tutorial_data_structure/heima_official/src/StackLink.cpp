#include "StackLink.h"

namespace ST_L
{

// 初始化
StackLink* init_StackLink()
{
    StackLink* stack = (StackLink*)malloc(sizeof(StackLink));
    stack->head.next = NULL;
    stack->size = 0;

    return stack;
}

// 入栈
void push_StackLink(StackLink* stack, LinkNode* data)
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

    // 新元素压入栈首
    data->next = stack->head.next;
    stack->head.next = data;
    stack->size++;
}

// 出栈
void pop_StackLink(StackLink* stack)
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

    stack->head.next = stack->head.next->next;
    stack->size--;
}

// 返回栈顶元素
LinkNode* top_StackLink(StackLink* stack)
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

    return stack->head.next;
}

// 返回栈元素个数
int getSize_StackLink(StackLink* stack)
{
    // check stack
    if(stack == NULL)
    {
        return -1;
    }

    return stack->size;
}

// 清空栈
void clear_StackLink(StackLink* stack)
{
    // check stack
    if(stack == NULL)
    {
        return;
    }

    // check size
    if(stack->size  == 0)
    {
        return;
    }

    stack->head.next = NULL;
    stack->size = 0;

}

// 销毁栈
void freeSpace_StackLink(StackLink* stack)
{
    // check stack
    if(stack == NULL)
    {
        return;
    }

    free(stack);
}



}