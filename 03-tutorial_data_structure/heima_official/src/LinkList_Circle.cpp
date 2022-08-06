#include "LinkList_Circle.h"


namespace CL
{

// 循环链表初始化
CircleLinkList* init_CircleLinkList()
{
    CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
    clist->head.next = &(clist->head);
    clist->size = 0;

    return clist;
}

// 插入
void insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data)
{
    // check clist
    if(clist == NULL)
    {
        return;
    }

    // check data
    if(data == NULL)
    {
        return;
    }

    // check pos
    if(pos < 0 || pos > clist->size)
    {
        pos = clist->size;
    }

    // 根据位置查找
    // 辅助指针变量
    CircleLinkNode* pCurrent = &(clist->head);
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    // 新数据插入链表
    data->next = pCurrent->next;
    pCurrent->next = data;
    clist->size++;

}

// 获取第一个元素
CircleLinkNode* getFront_CircleLinkList(CircleLinkList* clist)
{
    return clist->head.next;
}

// 根据位置删除
void removeByPos_CircleLinkList(CircleLinkList* clist, int pos)
{
    // check clist
    if(clist == NULL)
    {
        return;
    }

    // check pos
    if(pos < 0 || pos >= clist->size)
    {
        return;
    }

    // 根据pos寻找节点
    // 辅助指针变量
    CircleLinkNode* pCurrent = &(clist->head);
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    // 缓存当前节点的下一个节点
    CircleLinkNode* pNext = pCurrent->next;
    pCurrent->next = pNext->next;

    clist->size--;
}

// 根据值删除
void removeByVal_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
    // check clist
    if(clist == NULL)
    {
        return;
    }

    // check pos
    if(data == NULL)
    {
        return;
    }

    // 根据值寻找节点
    // 辅助指针变量
    CircleLinkNode* pPrev = &(clist->head);
    CircleLinkNode* pCurrent = pPrev->next;
    for(int i = 0; i < clist->size; i++)
    {
        if(compare(pCurrent, data) == CIRCLELINKLIST_TRUE)
        {
            pPrev->next = pCurrent->next;
            clist->size--;
            break;
        }
        pPrev = pCurrent;
        pCurrent = pPrev->next;
    }
}

// 获取链表长度
int getSize_CircleLinkList(CircleLinkList* clist)
{
    return clist->size;
}

// 查找
int find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare)
{
    // check clist
    if(clist == NULL)
    {
        return -1;
    }

    // check pos
    if(data == NULL)
    {
        return -1;
    }

    CircleLinkNode* pCurrent = clist->head.next;
    int flag = -1;
    for(int i = 0; i < clist->size; i++)
    {
        if(compare(pCurrent, data) == CIRCLELINKLIST_TRUE)
        {
            flag = i;
            break;
        }

        pCurrent = pCurrent->next;
    }


    return flag;
}

// 打印节点
void print_CircleLinkList(CircleLinkList* clist, PRINTNODE print)
{
    if(clist == NULL)
    {
        return;
    }

    // 辅助指针变量
    CircleLinkNode* pCurrent = clist->head.next;
    for(int i = 0; i < clist->size; i++)
    {
        if(pCurrent == &(clist->head))
        {
            pCurrent = pCurrent->next;
        }
        print(pCurrent);
        pCurrent = pCurrent->next;
    }

    std::cout << std::endl;
}

// 释放内存
void freeSpace_CircleLinkList(CircleLinkList* clist)
{
    // check clist
    if(clist == NULL)
    {
        return;
    }

    free(clist);
}

// 判断是否为空
int isEmpty_CircleLinkList(CircleLinkList* clist)
{
    if(clist->size == 0)
    {
        return CIRCLELINKLIST_TRUE;
    }

    return CIRCLELINKLIST_FALSE;
}


}