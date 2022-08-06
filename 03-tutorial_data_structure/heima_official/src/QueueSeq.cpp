#include "QueueSeq.h"

namespace QS
{

// 初始化
QueueSeq* init_QueueSeq()
{
    QueueSeq* queue = (QueueSeq*)malloc(sizeof(QueueSeq));
    queue->size = 0;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        queue->data[i] = NULL;
    }

    return queue;
}

// 入队
void push_QueueSeq(QueueSeq* queue, void* data)
{
    // check queue
    if(queue == NULL)
    {
        return;
    }

    // check data
    if(data == NULL)
    {
        return;
    }

    // check size
    if(queue->size == MAX_SIZE)
    {
        return;
    }

    // 数组左边作为队列头部
    queue->data[queue->size] = data;
    queue->size++;
}

// 出队
void pop_QueueSeq(QueueSeq* queue)
{
    // check queue
    if(queue == NULL)
    {
        return;
    }

    // check size
    if(queue->size == 0)
    {
        return;
    }

    // 所有元素前移
    for(int i = 0; i < queue->size-1; i++)
    {
        queue->data[i] = queue->data[i+1];
    }
    queue->size--;
}

// 返回队头元素
void* front_QueueSeq(QueueSeq* queue)
{
    // check queue
    if(queue == NULL)
    {
        return NULL;
    }

    // check size
    if(queue->size == 0)
    {
        return NULL;
    }

    return queue->data[0];
}

// 返回队尾元素
void* back_QueueSeq(QueueSeq* queue)
{
    // check queue
    if(queue == NULL)
    {
        return NULL;
    }

    // check size
    if(queue->size == 0)
    {
        return NULL;
    }

    return queue->data[queue->size-1];
}

// 返回大小
int getSize_QueueSeq(QueueSeq* queue)
{
    // check queue
    if(queue == NULL)
    {
        return -1;
    }

    return queue->size;
}

// 清空
void clear_QueueSeq(QueueSeq* queue)
{
    // check queue
    if(queue == NULL)
    {
        return;
    }

    queue->size = 0;
}

// 销毁
void freeSpace_QueueSeq(QueueSeq* queue)
{
    // check queue
    if(queue == NULL)
    {
        return;
    }

    free(queue);
}


}