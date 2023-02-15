#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

// 创建一个全局数组
int array[5000];
    
/**
 * @brief 求和数组前半段
 *
 * @param arg
 * @return void*
 */
void* sum_part1(void* arg)
{
    int sum = 0;
    for (int i = 0; i < 2500; ++i)
    {
        sum += array[i];
    }

    std::stringstream ss;
    ss << "before sum is " << sum << std::endl;
    std::cout << ss.str();
    return nullptr;
}

/**
 * @brief 求和数组后半段
 *
 * @param arg
 * @return void*
 */
void* sum_part2(void* arg) {
    int sum = 0;
    for (int i = 2500; i < 5000; ++i) {
        sum += array[i];
    }

    std::stringstream ss;
    ss << "front sum is " << sum << std::endl;
    std::cout << ss.str();
    return nullptr;
}


// 求和数组的范围
struct RANGE
{
    int begin, end, result;
};

/**
 * @brief 通过范围求和数组
 *
 * @param arg
 * @return void*
 */
void* sum_with_range(void* arg) {
    RANGE* range_ptr = (RANGE*)arg;

    int sum = 0;
    for (int i = range_ptr->begin; i < range_ptr->end; ++i) {
        sum += array[i];
    }
    range_ptr->result = sum;

    std::stringstream ss;
    ss << "sum of "
         << range_ptr->begin << " to " << range_ptr->end
         << " is " << sum << std::endl;
    std::cout << ss.str();

    return nullptr;
}

int main() {
    // create array
    for (int i = 0; i < 5000; i++) {
        array[i] = rand() % 50;  // 生成0~49之间的随机数，5000个
    }

    // sum with two threads with sum_part1() and sum_part2()
    pthread_t thread1, thread2;
    pthread_create(&thread1, nullptr, sum_part1, nullptr);
    pthread_create(&thread2, nullptr, sum_part2, nullptr);
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    // sum with two threads with range
    RANGE range1 = {0, 2500};
    RANGE range2 = {2500, 5000};
    pthread_create(&thread1, nullptr, sum_with_range, &range1);
    pthread_create(&thread2, nullptr, sum_with_range, &range2);
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    std::cout << "get result1: " << range1.result << std::endl;
    std::cout << "get result2: " << range2.result << std::endl;


    return 0;
}