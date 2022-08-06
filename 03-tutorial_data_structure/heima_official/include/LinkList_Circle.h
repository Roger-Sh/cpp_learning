#ifndef CIRCLELINK_H
#define CIRCLELINK_H

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <malloc.h>

using namespace std;


namespace CL
{


#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

// 循环链表小节点
typedef struct CIRCLELINKNODE
{
    struct CIRCLELINKNODE* next;
}CircleLinkNode;

// 循环链表结构体
typedef struct CIRCLELINKLIST
{
    CircleLinkNode head;
    int size;
}CircleLinkList;


// 函数指针，比较回调
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);

// 函数指针，打印回调
typedef void(*PRINTNODE)(CircleLinkNode*);

// 循环链表初始化
CircleLinkList* init_CircleLinkList();

// 插入
void insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

// 获取第一个元素
CircleLinkNode* getFront_CircleLinkList(CircleLinkList* clist);

// 根据位置删除
void removeByPos_CircleLinkList(CircleLinkList* clist, int pos);

// 根据值删除
void removeByVal_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

// 获取链表长度
int getSize_CircleLinkList(CircleLinkList* clist);

// 查找
int find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

// 打印节点
void print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

// 释放内存
void freeSpace_CircleLinkList(CircleLinkList* clist);

// 判断是否为空
int isEmpty_CircleLinkList(CircleLinkList* clist);



}




#endif 