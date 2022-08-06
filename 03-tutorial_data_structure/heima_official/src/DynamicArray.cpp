#include "DynamicArray.h"


namespace DA
{


// 初始化动态数组
Dynamic_Array* init_dynamic_array()
{

    // 动态数组申请内存    
    Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));

    // 初始化
    myArray->size = 0;          // 长度
    myArray->capacity = 20;     // 容量
    myArray->pAddr = (int*)malloc(sizeof(int)*myArray->capacity);   // 数据首地址

    return myArray;
}

// push_back
void push_back_dynamic_array(Dynamic_Array* arr, int val)
{
    // check NULL
    if(arr == NULL)
    {
        return ;
    }

    // 判断空间是否足够
    // 如果空间不够，则申请更大的空间，拷贝原来的内存数据到新的空间，并释放原来的内存
    if(arr->size == arr->capacity)
    {
        // 申请更大的内存空间，新空间是旧空间的两倍
        int* newSpace = (int*)malloc(sizeof(int)*arr->capacity*2);
    
        // 拷贝数据到新的空间
        memcpy(newSpace, arr->pAddr, arr->capacity*sizeof(int));

        // 释放旧空间内存
        free(arr->pAddr);

        // 更新容量和数据首地址
        arr->capacity = arr->capacity*2;
        arr->pAddr = newSpace;
    }

    // 插入新元素
    arr->pAddr[arr->size] = val;
    arr->size++;
}

// remove by pos
void removeByPos_dynamic_array(Dynamic_Array* arr, int pos)
{
    // check NULL
    if(arr == NULL)
    {
        return;
    }

    // 判断位置是否有效
    if(pos < 0 || pos >= arr->size)
    {
        return;
    }

    // 删除元素，前移后面的所有元素
    for(int i = pos; i < arr->size-1; i++)
    {
        arr->pAddr[i] = arr->pAddr[i+1];
    }

    arr->size--;
}

// remove by val, first pos 
void removeByVal_dynamic_array(Dynamic_Array* arr, int val)
{
    // check NULL
    if(arr == NULL)
    {
        return;
    }

    // 找到值的位置
    int pos = find_dynamic_array(arr, val);

    // 根据位置删除
    removeByPos_dynamic_array(arr, pos);
}

// find
int find_dynamic_array(Dynamic_Array* arr, int val)
{
    // check NULL
    if(arr == NULL)
    {
        return -1;
    }

    // 找到值的位置
    int pos = -1;
    for(int i = 0; i<arr->size; i++)
    {
        if(arr->pAddr[i] == val)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

// print 
void print_dynamic_array(Dynamic_Array* arr)
{
    // check NULL
    if(arr == NULL)
    {
        return;
    }

    // 遍历输出
    for(int i = 0; i < arr->size; i++)
    {
        std::cout << arr->pAddr[i] << " ";
    }
    std::cout << std::endl;
}

// free space
void freespace_dynamic_array(Dynamic_Array* arr)
{
    // check NULL
    if(arr == NULL)
    {
        return ;
    }

    if(arr->pAddr != NULL)
    {
        free(arr->pAddr);
    }

    free(arr);
}

// clear space
void clear_dynamic_array(Dynamic_Array* arr)
{
    // check NULL
    if(arr == NULL)
    {
        return ;
    }

    arr->size = 0;
}

// get capacity
int getCapacity_dynamic_array(Dynamic_Array* arr)
{
    // check NULL
    if(arr == NULL)
    {
        return -1;
    }

    return arr->capacity;
}

// get size
int getSize_dynamic_array(Dynamic_Array* arr)
{
    // check NULL
    if(arr == NULL)
    {
        return -1;
    }

    return arr->size;
}

// get element at pos
int at_dynamic_array(Dynamic_Array* arr, int pos)
{
    // check NULL
    if(arr == NULL)
    {
        return -1;
    }

    return arr->pAddr[pos];
}

}