#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <malloc.h>

using namespace std;


namespace LL
{

// 链表节点
typedef struct LINKNODE
{
    void* data;             // 无名指针，指向任何类型的数据
    struct LINKNODE* next;  // 指向下一个节点的指针
}LinkNode;


// 链表结构体
typedef struct LINKLIST
{
    LinkNode* head;
    int size;
}LinkList;


// 函数指针，之后可以自定义打印函数
typedef void(*PRINTLINKNODE)(void*);

// 初始化链表
LinkList* init_LinkList();

// 指定位置插入
void insert_LinkList(LinkList* list, int pos, void* data);

// 删除指定位置的值
void removeByPos_LinkList(LinkList* list, int pos);

// 获得链表长度
int getSize_LinkList(LinkList* list);

// 返回第一个节点
void* getFront_LinkList(LinkList* list);

// 查找
int find_LinkList(LinkList* list, void* data);

// 打印
void print_LinkList(LinkList* list, PRINTLINKNODE print);

// 释放链表内存
void freeSpace_LinkList(LinkList* list);


}


#endif 