#ifndef LINKLISTDOUBLE_H
#define LINKLISTDOUBLE_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>


namespace LLD
{

#define LINKLISTDOUBLE_TRUE 1
#define LINKLISTDOUBLE_FALSE 0

// 链表小节点
typedef struct LINKNODEDOUBLE
{
    struct LINKNODEDOUBLE* prev;
    struct LINKNODEDOUBLE* next;
}LinkNodeDouble;

// 链表节点
typedef struct LINKLSTDOUBLE
{
    LinkNodeDouble head;
    int size;
}LinkListDouble;

// 函数指针，自定义打印函数
typedef void(*PRINTNODE)(LinkNodeDouble*);

// 函数指针，自定义比较函数
typedef int(*COMPARENODE)(LinkNodeDouble*, LinkNodeDouble*);

// 初始化链表
LinkListDouble* init_LinkListDouble();

// 插入
void insert_LinkListDouble(LinkListDouble* list, int pos, LinkNodeDouble* data);

// 根据位置删除
void removeByPos_LinkListDouble(LinkListDouble* list, int pos);

// 根据值删除
void removeByVal_LinkListDouble(LinkListDouble* list, LinkNodeDouble* data, COMPARENODE compare);

// 获取第一个元素
LinkNodeDouble* getFront_LinkListDouble(LinkListDouble* list);

// 获取最后一个元素
LinkNodeDouble* getBack_LinkListDouble(LinkListDouble* list);

// 从前端查找
int findFront_LinkListDouble(LinkListDouble* list, LinkNodeDouble* data, COMPARENODE compare);

// 从后端查找
int findBack_LinkListDouble(LinkListDouble* list, LinkNodeDouble* data, COMPARENODE compare);

// 返回链表长度
int getSize_LinkListDouble(LinkListDouble* list);

// 从前端打印
void printFront_LinkListDouble(LinkListDouble* list, PRINTNODE print);

// 从后端打印
void printBack_LinkListDouble(LinkListDouble* list, PRINTNODE print);

// 释放链表内存
void freeSpace_LinkListDouble(LinkListDouble* list);

// 判断是否为空
int isEmpty_LinkListDouble(LinkListDouble* list);


} // namespace LLD


#endif // LINKLISTDOUBLE_H