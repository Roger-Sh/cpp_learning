#include "QueueLink.h"

namespace QL
{
// 初始化
QueueLink* init_QueueLink()
{
    QueueLink* queue = (QueueLink*)malloc(sizeof(QueueLink));
    queue->head.next = NULL;
    queue->rear = &(queue->head);
    queue->size = 0;

    return queue;
}


// 入队列
void push_QueueLink(QueueLink* queue, LinkNode* data)
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

    // 新元素压入队尾
    data->next = NULL;
    queue->rear->next = data;
    queue->rear = data;

    queue->size++;
}

// 出队列
void pop_QueueLink(QueueLink* queue)
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

    if(queue->size == 1)
    {
        queue->head.next = NULL;
        queue->rear = &(queue->head);
        queue->size--;
        return;
    }

    // 弹出队头元素
    queue->head.next = queue->head.next->next;
    queue->size--;
}

// 返回队头元素
LinkNode* front_QueueLink(QueueLink* queue)
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

    return queue->head.next;
}

// 返回队尾元素
LinkNode* back_QueueLink(QueueLink* queue)
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

    return queue->rear;
}

// 返回队列元素个数
int getSize_QueueLink(QueueLink* queue)
{
    // check queue
    if(queue == NULL)
    {
        return -1;
    }

    return queue->size;
}

// 清空队列元素
void clear_QueueLink(QueueLink* queue)
{
    // check queue
    if(queue == NULL)
    {
        return;
    }

    // check queue
    if(queue->size == 0)
    {
        return;
    }

    queue->size = 0;
    queue->head.next = NULL;
    queue->rear = &(queue->head);
}

// 销毁队列
void freeSpace_QueueLink(QueueLink* queue)
{
    // check queue
    if(queue == NULL)
    {
        return;
    }

    free(queue);
}

} // namespace QL