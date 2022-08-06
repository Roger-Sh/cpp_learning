#include "LinkList_Double.h"

namespace LLD
{

// 初始化链表
LinkListDouble* init_LinkListDouble()
{
    LinkListDouble* list = (LinkListDouble*)malloc(sizeof(LinkListDouble));
    list->head.next = &(list->head);
    list->head.prev = &(list->head);
    list->size = 0;

    return list;
}

// 插入
// 通过双向链表的机制，自动判断插入位置靠前还是靠后
void insert_LinkListDouble(LinkListDouble* list, int pos, LinkNodeDouble* data)
{
    // check list
    if(list == NULL)
    {
        return;
    }
    
    // check data
    if(data == NULL)
    {
        return;
    }

    // check pos
    if(pos > list->size)
    {
        pos = list->size;
    }

    if(pos < -(list->size+1))
    {
        pos = -(list->size+1);
    }

    LinkNodeDouble* pCurrent = &(list->head);
    // 正向插入
    if(pos >= 0)
    {
        // 查找正向插入位置
        for(int i = 0; i < pos; i++)
        {
            pCurrent = pCurrent->next;
        }

        // 插入新节点
        data->next = pCurrent->next;
        data->prev = pCurrent;
        pCurrent->next = data;
        data->next->prev = data;
    }
    // 反向插入
    else
    {
        // 查找反向插入的位置
        for(int i = -1; i > pos; i--)
        {
            pCurrent = pCurrent->prev;
        }

        // 插入新节点
        data->prev = pCurrent->prev;
        data->next = pCurrent;
        pCurrent->prev = data;
        data->prev->next = data;
    }
    list->size++;

}

// 根据位置删除
void removeByPos_LinkListDouble(LinkListDouble* list, int pos)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    // check pos
    if(pos >= list->size || pos <= -(list->size+1))
    {
        return;
    }

    // 根据pos寻找节点
    // 辅助指针变量
    LinkNodeDouble* pCurrent = &(list->head);
    if(pos >= 0)
    {
        for (int i = 0; i < pos; i++)
        {
            pCurrent = pCurrent->next;
        }

        LinkNodeDouble* pNext = pCurrent->next;
        pCurrent->next = pNext->next;
        pNext->next->prev = pCurrent;
    }
    else
    {
        for(int i = -1; i > pos; i--)
        {
            pCurrent = pCurrent->prev;
        }

        LinkNodeDouble* pPrev = pCurrent->prev;
        pCurrent->prev = pPrev->prev;
        pPrev->prev->next = pCurrent;
    }

    list->size--;
}

// 根据值删除
void removeByVal_LinkListDouble(LinkListDouble* list, LinkNodeDouble* data, COMPARENODE compare)
{
    // check list
    if(list == NULL)
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
    LinkNodeDouble* pCurrent = &(list->head);
    for(int i = 0; i < list->size; i++)
    {
        if(compare(pCurrent, data) == LINKLISTDOUBLE_TRUE)
        {
            pCurrent->prev->next = pCurrent->next;
            pCurrent->next->prev = pCurrent->prev;
            list->size--;
            break;
        }
        pCurrent = pCurrent->next;
    }
}


// 获取第一个元素
LinkNodeDouble* getFront_LinkListDouble(LinkListDouble* list)
{
    // check list
    if(list == NULL)
    {
        return NULL;
    }

    return list->head.next;
}

// 获取最后一个元素
LinkNodeDouble* getBack_LinkListDouble(LinkListDouble* list)
{
    // check list
    if(list == NULL)
    {
        return NULL;
    }

    return list->head.prev;
}

// 从前端查找
int findFront_LinkListDouble(LinkListDouble* list, LinkNodeDouble* data, COMPARENODE compare)
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

    LinkNodeDouble* pCurrent = list->head.next;
    int flag = -1;
    for (int i = 0; i < list->size; i++)
    {
        if(compare(pCurrent, data) == LINKLISTDOUBLE_TRUE)
        {
            flag = i;
            break;
        }

        pCurrent = pCurrent->next;
    }
    
    return flag;
}

// 从后端查找
int findBack_LinkListDouble(LinkListDouble* list, LinkNodeDouble* data, COMPARENODE compare)
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

    LinkNodeDouble* pCurrent = list->head.prev;
    int flag = 0;
    for (int i = -1; i > -(list->size+1); i--)
    {
        if(compare(pCurrent, data) == LINKLISTDOUBLE_TRUE)
        {
            flag = i;
            break;
        }

        pCurrent = pCurrent->prev;
    }
    
    return flag;
}

// 返回链表长度
int getSize_LinkListDouble(LinkListDouble* list)
{
    // check list
    if(list == NULL)
    {
        return -1;
    }

    return list->size;
}

// 从前端打印
void printFront_LinkListDouble(LinkListDouble* list, PRINTNODE print)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    // 辅助指针变量
    LinkNodeDouble* pCurrent = list->head.next;
    for(int i = 0; i < list->size; i++)
    {
        if(pCurrent == &(list->head))
        {
            pCurrent = pCurrent->next;
        }
        print(pCurrent);
        pCurrent = pCurrent->next;
    }

    std::cout << std::endl;
}

// 从后端打印
void printBack_LinkListDouble(LinkListDouble* list, PRINTNODE print)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    // 辅助指针变量
    LinkNodeDouble* pCurrent = list->head.prev;
    for(int i = -1; i > -(list->size+1); i--)
    {
        if(pCurrent == &(list->head))
        {
            pCurrent = pCurrent->prev;
        }
        print(pCurrent);
        pCurrent = pCurrent->prev;
    }
    std::cout << std::endl;
}

// 释放链表内存
void freeSpace_LinkListDouble(LinkListDouble* list)
{
    // check list
    if(list == NULL)
    {
        return;
    }

    free(list);

}

// 判断是否为空
int isEmpty_LinkListDouble(LinkListDouble* list)
{
    if(list->size == 0)
    {
        return LINKLISTDOUBLE_TRUE;
    }
    return LINKLISTDOUBLE_FALSE;
}


} // namespace LLD