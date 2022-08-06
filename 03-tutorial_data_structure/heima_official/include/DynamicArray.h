#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <malloc.h>
#include <cstring>

using namespace std;


namespace DA
{

// 动态增长内存，将存放数据的内存放在堆上
// 申请内存，拷贝数据，释放内存
// 容量 capacity 可以存放多少元素
// 大小 size 当前元素的个数


/*
 动态数组结构体
*/

typedef struct DYNAMICARRAY
{
    int* pAddr;     // 存放数据的首地址
    int size;       // 大小，当前有多少个元素
    int capacity;   // 容量，容器当前最大能容纳多少元素
}Dynamic_Array;

/* 
对DYNAMICARRAY结构体的操作函数
*/

// init
Dynamic_Array* init_dynamic_array();

// push_back
void push_back_dynamic_array(Dynamic_Array* arr, int val); 

// remove by pos
void removeByPos_dynamic_array(Dynamic_Array* arr, int pos);

// remove by val
void removeByVal_dynamic_array(Dynamic_Array* arr, int val);

// find
int find_dynamic_array(Dynamic_Array* arr, int val);

// print 
void print_dynamic_array(Dynamic_Array* arr);

// free space
void freespace_dynamic_array(Dynamic_Array* arr);

// clear space
void clear_dynamic_array(Dynamic_Array* arr);

// get capacity
int getCapacity_dynamic_array(Dynamic_Array* arr);

// get size
int getSize_dynamic_array(Dynamic_Array* arr);

// get element at pos
int at_dynamic_array(Dynamic_Array* arr, int pos);

}

#endif 