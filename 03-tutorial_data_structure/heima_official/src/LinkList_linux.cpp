#include "LinkList_linux.h"


namespace LLL
{
    
// 初始化链表
LinkList* init_LinkList()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head.next = NULL;
    list->size = 0;

    return list; 
}

// 插入
void insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    if(data == NULL)
    {
        return;
    }

    if(pos < 0 || pos > list->size)
    {
        pos = list->size;
    }

    // 查找插入位置
    LinkNode* pCurrent = &(list->head);
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    // 插入新节点
    data->next = pCurrent->next;
    pCurrent->next = data;

    list->size++;
}

// 删除
void remove_LinkList(LinkList* list, int pos)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    // check pos
    if(pos < 0 || pos >= list->size)
    {
        return;
    }

    // 辅助指针变量
    LinkNode* pCurrent = &(list->head);
    for(int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    //删除节点
    pCurrent->next = pCurrent->next->next;
    list->size--;

}

// 查找
int find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare)
{
    // check list
    if(list == NULL)
    {
        return -1;
    }

    // check data
    if(data == NULL)
    {
        return -1;
    }

    // 辅助指针变量
    LinkNode* pCurrent = list->head.next;
    int index = 0;
    int flag = -1;
    while(pCurrent != NULL)
    {
        if(compare(pCurrent, data) == 0)
        {
            flag = index;
            break;
        }
        pCurrent = pCurrent->next;
        index++;
    }

    return flag;
}

// 返回链表长度
int getSize_LinkList(LinkList* list)
{
    return 0;
}

// 打印
void print_LinkList(LinkList* list, PRINTNODE print)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    // 遍历
    LinkNode* pCurrent = list->head.next;
    while(pCurrent != NULL)
    {
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
}

// 释放链表内存
void freeSpace_LinkList(LinkList* list)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    list = NULL;
    free(list);
}


}