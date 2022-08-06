#include <iostream>
#include <iomanip>

using namespace std;


template<typename T, int N>
void print_data(T (&data)[N])
{
    for(int i = 0; i<N; i++)
    {
        cout << setw(5) << data[i]; 
    }
    cout << endl;
}


/*
冒泡排序，从前往后比较相邻元素，完整扫描一次能确保最后的元素是最大的，下次扫描长度减一
数据长度n，总扫描次数n-1次，每次扫描比较 n-1-i次，i为当前扫描的序号
最坏情况和平均情况下需比较n(n-1)/2次，时间复杂度O(n^2),
最好情况比较n-1次，时间复杂度O(n)
比较后才决定是否互换，所以为稳定排序
只需一个额外空间，空间复杂度最佳
适用于数据量小或者已经部分排过序的情况
缺点：无论数据是否已排序完成，都会执行n(n-1)/2操作，所以在内层循环中加入一个flag帮助判断是否已经提前完成排序
*/
template<typename T, int N>
void sort_bubble(T (&data)[N])
{
    for(int i = 0; i < N-1; i++)            // 扫描次数，n-1次
    {
        int flag = 0;

        for(int j = 0; j < N-1-i; j++)      // 每次扫描的长度 n-1-i
        {
            if(data[j] > data[j+1])         // 比较， 交换
            {
                T tmp;
                tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                flag++;
            }
        }

        if(flag == 0)                       // 判断是否已完成排序
        {
            break;
        }
        cout << "after " << i << ". bubble_sort: \n";
        print_data(data);   
    }

    cout << "=========" << endl;
}


/*
选择排序
每次扫描把第一个与后面所有元素对比，下次扫描从下一个开始
扫描N-1次，每次扫描比较N-1-i次，i为当前扫描序号
最好，平均，最坏情况都需比较n(n-1)/2次，时间复杂度O(n^2)
空间复杂度为1
排序每次扫描最大值或者最小值与最前方未排序的的键值交换，顺序有可能被改变，所以不是稳定排序
适合数据量小或者部分数据已经排序的情况
*/
template <typename T, int N>
void sort_select(T (&data)[N])
{
    for(int i=0; i<N-1; i++)    // 扫描 N-1次
    {
        for(int j=i+1; j<N; j++)    // 每次扫描比较
        {
            if(data[i] > data[j])
            {
                T tmp;
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
        cout << "after " << i << ".select_sort: \n";
        print_data(data);
    }
    cout << "=========" << endl;

}


/*
插入排序
先将两个元素排序，再将后续元素一一插入到合适的位置
最坏以及平均情况需比较n(n-1)/2 时间复杂度O(n^2)
最好情况比较n次，时间复杂度O(n)
插入排序是稳定排序
只需一个额外空间，空间复杂度最佳
适用于大部分数据已经排序，或者在已排序的数据库中添加新数据
插入排序会造成大量搬移，建议使用链表
*/
template<typename T, int N>
void sort_insert(T (&data)[N])
{
    for(int i = 1; i < N; i++)              // 扫描 N-1次，从第二个元素开始扫描
    {
        T tmp;
        tmp = data[i];                      // 将当前要插入的元素放入暂存区
        int j = i - 1;                      // 前一个元素的位置
        while( j >= 0 && tmp < data[j])     // 循环满足还有前一个元素，以及前一个元素比当前暂存区的元素大
        {
            data[j+1] = data[j];            // 满足循环的元素后移一位
            j--;                            
        }

        data[j+1] = tmp;                    // 插入当前元素

        cout << "after " << i << ".insert_sort: \n";
        print_data(data);
    }


}


/*
希尔排序法
用以减少插入排序法中的数据搬移次数
原理是将数据区分成特定间隔的小区块，以插入排序法排完区块内的内容后，再减少间隔的距离
首先将所有数据N分成Y份，用质数来划分，习惯选2，则获得N/2 = Y 份数据，每个区块中元素的间隔为Y
对区块内的内容排序后放回原位，接着缩小间隔再除以2，再用插入排序，重复该步骤

希尔排序法的分析
任何情况时间复杂度为 O(n^(3/2))
稳定排序
只需一个额外空间，空间复杂度最佳
适用于大部分数据都已排序的情况
*/
template<typename T, int N>
void sort_shell(T (&data)[N])
{
    int i;      //扫描次数
    int j;      //用j来定位比较的元素
    int k=1;    //计数
    T tmp;      //暂存
    int jmp;    //设置间距位移量

    jmp = N / 2;    // 初始化间距位移量    
    while(jmp != 0)
    {
        for(i = jmp; i < N; i++)
        {
            // 插入排序，间距为jmp
            tmp = data[i];  // 当前要插入的元素
            j = i - jmp;    // 前一个间隔距离的元素

            while(tmp < data[j] && j >= 0)  // 当前一个间隔距离的元素存在且比现在的元素大时
            {
                data[j+jmp] = data[j];      // 将前一个间隔距离的元素移到现在的距离
                j = j - jmp;                // 去看看更加前一个的间隔距离的元素
            }
            data[jmp+j] = tmp;              // 将现在的元素放在最前一个比现在元素小的位置上
        }

        jmp = jmp/2;    // 缩小间隔距离
        cout << "after " << k++ << ".shell_sort: \n";
        print_data(data);
    }
}


/*
快速排序
又称分割交换排序法，目前公认最佳的排序法，使用分而治之的方法
在数据中找一个虚拟值，按照此虚拟值将所有数据分为两部分，
小于中间值的放左边，大于中间值的放右边，重复此过程处理两边的数据，直到排序结束。

步骤：
假设有n个数据1 - n, 值为K1 - Kn

1 先假设K的值为第一个键值
2 从左到右找出Ki, 使得Ki > K
3 从右到左找出Kj, 使得Kj < K
4 如果 i<j, 那么Ki 与 Kj 互换，并回到步骤2
5 如果 i>=j, 那么K 与 Kj 互换，并以j为基准点分割成左右两部分，  (此时Kj 右边都比K 大，Kj左边都比K小)
  然后针对左右两边执行步骤1-5，直到左边键值等于右边键值 (使用)

分析：
最好以及平均情况下，时间复杂度为O(nlog_2(n))
最坏情况下，时间复杂度为O(n^2),每次挑中的中间值不是最大就是最小
快排不是稳定排序法
最坏情况下，空间复杂度为O(n),最好情况下，空间复杂度为O(log_2(n))
快排是平均运行时间最短的排序法。

快排对于重复数据不太擅长，查找i j时不能用<= 或者 >= 
尝试三相切割
*/

template<typename T, int N>
void sort_quick(T (&data)[N], int lf, int rg)
{
    int tmp;
    int lf_idx;
    int rg_idx;
    int t;

    // 第一个键值为 data[0]
    if(lf < rg)
    {
        lf_idx = lf + 1;    // 1
        rg_idx = rg;        // N - 1

        while(1)
        {
            print_data(data);

            // 从左向右找出值大于data[lf]
            for(int i = lf+1; i <= rg; i++)
            {
                if(data[i] > data[lf])
                {
                    lf_idx = i;
                    break;
                }
                lf_idx++;   // 如果找不出比data[lf]更大的，则用最大的索引
            }
            
            // 从右向左找出键值小于data[lf]
            for(int j = rg; j >= lf+1; j--)
            {
                if(data[j] < data[lf])
                {
                    rg_idx = j;
                    break;
                }
                rg_idx--;   // 如果找不出比data[lf]更小的，则用最小的索引
            }

            // 如果lf_idx < rg_idx，则交换这两个值
            if(lf_idx < rg_idx)
            {
                tmp = data[lf_idx];
                data[lf_idx] = data[rg_idx];
                data[rg_idx] = tmp;
            }
            else    // 否则跳出循环
            {
                break;
            }
        }

        // 如果lf_idx >= rg_idx，则交换data[lf] 与 data[rg_idx]
        if(lf_idx >= rg_idx)
        {
            // 交换K 与 data[lf_idx]
            tmp = data[rg_idx];
            data[rg_idx] = data[lf];
            data[lf] = tmp;

            // 以rg_idx 为基准点 分成左右两部分
            // 以递归的方式分别对左右两部分排序
            sort_quick(data, lf, rg_idx-1);
            sort_quick(data, rg_idx+1, rg);
        }
    }
}


/*
合并排序，归并排
针对已排序好的两个或两个以上数据组，通过合并方式组合成大的排序好的数列
步骤：
1 N个长度为1的键值成对合并成N/2长度为2的键值组
2 N/2 长度为2的键值组成对合并成N/4长度为4的键值组
3 将键值组不断合并，直到合并成长度为N的简直组

分析：
最好，最坏，平均时间复杂度O(nlog_2(n))
空间复杂度O(n)，需要一个同样大小为N的额外空间
归并排是稳定排序法
*/
template<typename T, int N, int M>
void sort_merge(T (&data1)[N], T (&data2)[M], T (&data_merge)[N+M])
{
    int i = 0;  // data1 index
    int j = 0;  // data2 index
    int k = 0;  // data_merge index

    while(i < N && j < M)
    {
        if(data1[i] <= data2[j])
        {
            data_merge[k] = data1[i];
            i++;    // 更新 data1 index
        }
        else
        {
            data_merge[k] = data2[j];
            j++;    // 更新 data2 index
        }
        k++;
    }

    while(i < N)
    {
        data_merge[k] = data1[i];
        k++;
        i++;
    }
    while(j < N)
    {
        data_merge[k] = data2[j];
        k++;
        j++;
    }
}





/*
基数排序 分配模式排序方式
分为 MSD(Most Significant Digit First), LSD(Least Significant Digit First)
MSD: 从最左位开始比较
LSD: 从最右边开始比较
分析：
所有情况下时间复杂度O(nlog_p^(k), k为原始数据最大值)
基数排序是稳定排序
基数排序需要很大的额外空间存放列表数据，空间复杂度为O(n*p), 
n为原始数据个数，p是数据字符数，若n很大，p固定或很小，则基数排序效率很高

*/
template<int N>
void sort_radix(int (&data)[N])
{
    // n为基数，从个位开始排序
    for(int n = 1; n <= 100; n=n*10)
    {
        // 暂存数组 [0-9][数据总个数]， 所有内容为0
        int tmp[10][100] = {0};

        // 对比所有数据
        for(int i=0; i<N; i++)
        {
            // m 为n位数的值，比如 36 个位数 36/1%10 = 6, 十位数 36/10%10 = 3
            int m = (data[i]/n)%10;
            tmp[m][i] = data[i];
        }

        int k=0;
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(tmp[i][j] != 0)
                {
                    data[k] = tmp[i][j];
                    k++;
                }
            }
        }

        cout << "after " << n << " radix_sort: " << endl;
        print_data(data);
    }
}



/**
 *  堆积树排序 heap sort
 *  一种特殊的二叉树排序，分为最大堆积树与最小堆积树
 *  所有情况下 时间复杂度为 O(nlog_2(n))
 *  堆积排序法不是稳定排序法
 *  只需要一个额外的空间，空间复杂度为O(1)
 */
template<typename T>
void ad_heap(T &data, int i, int size)
{
    int j, tmp, post;

    j = 2*i;
    tmp = data[i];
    post = 0;

    while(j <= size && post == 0)
    {
        if(j < size)
        {
            if(data[j] < data[j+1])
            {
                j++;
            }
        }
        if(tmp >= data[j])  // 如果树根较大，则结束比较过程
        {
            post = 1;           
        }
        else                // 树根较小，则继续比较
        {
            data[j/2] = data[j];

            j = 2*j;
        }
    }

    // 指定树根为父节点
    data[j/2] = tmp;
}  


template<typename T, int N>
void heap(T (&data)[N])
{
    int i, j, tmp;

    for(int i = (N/2); i > 0; i--)
    {
        ad_heap(data, i, N-1);   
    }

    cout << "orignal heap: \n";
    print_data(data);
}




int main()
{
    // int data[12] = {6, 5, 9, 7, 2, 8};
    // int data[6] = {4,6,2,7,8,9};
    // int data[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    // int data_len = sizeof(data)/sizeof(int);
    // cout << "original data: \n";
    // print_data(data);
    // cout << "=========" << endl;


    // // 冒泡排序
    // sort_bubble(data);
    
    // // 选择排序
    // sort_select(data);

    // // 插入排序
    // sort_insert(data);

    // // 希尔排序
    // sort_shell(data);

    // // 快速排序
    // sort_quick(data, 0, data_len - 1);

    // // 归并排序
    // int data1[7] = {2,4,7,4,5,9,1};
    // int data2[9] = {2,8,4,0,2,1,5,8,2};
    // int data3[16];
    // print_data(data1);
    // print_data(data2);

    // sort_quick(data1, 0, 6);
    // sort_quick(data2, 0, 8); 

    // sort_merge(data1, data2, data3);
    // print_data(data3);

    // // 基数排序
    // int data_radix[] = {123, 78, 950, 29, 481, 29, 344, 2, 238, 23, 285, 69};
    // sort_radix(data_radix); 
    
    
    int data_heap[] = {9,8,7,6,5,4,3,2,1};
    heap(data_heap);
    
    return 0;
}