#ifndef LINKLIST_LINUX_H
#define LINKLIST_LINUX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

namespace LLL
{


// 链表小节点
typedef struct LINKNODE
{
    struct LINKNODE* next;
}LinkNode;


// 链表节点
typedef struct LINKLIST
{
    LinkNode head;
    int size;
}LinkList;

// 函数指针，自定义打印函数
typedef void(*PRINTNODE)(LinkNode*);

// 函数指针，自定义比较函数
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

// 初始化链表
LinkList* init_LinkList();

// 插入
void insert_LinkList(LinkList* list, int pos, LinkNode* data);

// 删除
void remove_LinkList(LinkList* list, int pos);

// 查找
int find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);

// 返回链表长度
int getSize_LinkList(LinkList* list);

// 打印
void print_LinkList(LinkList* list, PRINTNODE print);

// 释放链表内存
void freeSpace_LinkList(LinkList* list);


}

#endif