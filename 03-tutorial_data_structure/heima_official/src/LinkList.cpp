#include "LinkList.h"

namespace LL
{


// 初始化链表
LinkList* init_LinkList()
{

    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;

    return list;
}

// 指定位置插入
void insert_LinkList(LinkList* list, int pos, void* data)
{
    // check args
    if(list == NULL)
    {
        return;
    }
    if(data == NULL)
    {
        return;
    }

    // check pos
    if(pos < 0 || pos > list->size)
    {
        pos = list->size;
    }

    // new node
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->data = data;
    newnode->next = NULL;

    // find pos node
    LinkNode* pCurrent = list->head;
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    // insert new node
    newnode->next = pCurrent->next;
    pCurrent->next = newnode;
    list->size++;
}

// 删除指定位置的值
void removeByPos_LinkList(LinkList* list, int pos)
{
    // check args
    if(list == NULL)
    {
        return;
    }
    if(pos < 0 || pos >= list->size)
    {
        return;
    }

    // find pos
    LinkNode* pCurrent = list->head;
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    // 缓存删除的节点，插入之后的节点
    LinkNode* pDelete = pCurrent->next;
    pCurrent->next = pDelete->next;

    // 释放删除的节点
    free(pDelete);
    list->size--;
}


// 获得链表长度
int getSize_LinkList(LinkList* list)
{
    return list->size;
}

// 返回第一个节点
void* getFront_LinkList(LinkList* list)
{
    return list->head->next;
}

// 查找
int find_LinkList(LinkList* list, void* data)
{
    // check args
    if(list == NULL)
    {
        return -1;
    }
    if(data == NULL)
    {
        return -1;
    }

    // 遍历查找
    LinkNode* pCurrent = list->head->next;
    int i = 0;
    while(pCurrent != NULL)
    {
        if(pCurrent->data == data)
        {
            break;
        }
        i++;
        pCurrent = pCurrent->next;
    }

    return i;
}

// 打印
void print_LinkList(LinkList* list, PRINTLINKNODE print)
{
    // check args
    if(list == NULL)
    {
        return;
    }

    // 遍历
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != NULL)
    {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }

}

// 释放链表内存
void freeSpace_LinkList(LinkList* list)
{
    // check args
    if(list == NULL)
    {
        return;
    }

    // 遍历
    LinkNode* pCurrent = list->head;
    while(pCurrent != NULL)
    { 
        // 缓存下一个节点
        LinkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    // 释放链表内存
    list->size = 0;
    free(list);
}

}