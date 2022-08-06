#pragma once   	//为了避免同一个头文件被包含(include)多次
#include <iostream>
using namespace std;

#include "worker.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    // 构造函数
    WorkerManager();

    // 析构函数
    ~WorkerManager();

    // show menu
    void show_menu();

    // exit system
    void exit_system();

    // add worker
    // 分析：
    // 用户在批量创建时，可能会创建不同种类的职工
    // 如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里
    // 如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker **的指针维护
    void add_worker();

    // 保存数据
    void save();

    // 获取记录的职工人数
    int get_WorkerNum();

    // 初始化职工数组
    void init_Worker();

    // 显示职工信息
    void show_worker();

    // 删除职工
    void del_worker();

    // 检查职工是否存在
    int isExit(int ID);

    // 修改职工信息
    void mod_worker();

    // 查找员工，通过职工编号或者通过名字
    void find_worker();

    // 排序
    void sort_worker();

    // 清空
    void clean_file();

public:
    // worker name
    int m_workerNum;

    // worker array
    Worker ** m_workerArray;

    // flag file is empty
    bool m_FileIsEmpty;


};
