#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <mutex>
#include <sstream>

// 全局变量s
int s = 0;

// 全局变量s的互斥锁
std::mutex s_lock;

/**
 * @brief 对全局变量循环+1 1000000次
 *
 * @param arg
 * @return void*
 */
void* count(void* arg) {
    for (int i; i < 100000; i++) {
        s++;
    }
        
    return nullptr;
}

/**
 * @brief 用两个线程共同计数，每个线程计数100万次，我们预想的最终计数应该是200万：
 * 结果每次都不同，但都达不到200万
 * 原因：第二个线程读取了第一个线程没有处理完的结果，
 * 两个线程之间的结果相互覆盖。
 * race condition竞争条件：由于两个或者多个进程竞争使用不能被同时访问的资源，
 * 使得这些进程有可能因为时间上推进的先后原因而出现问题。
 */
void test01() {
    pthread_t th1, th2;
    pthread_create(&th1, nullptr, count, nullptr);
    pthread_create(&th2, nullptr, count, nullptr);
    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);
    std::cout << "count is " << s << std::endl;
}

/**
 * @brief 对全局变量循环+1 1000000次
 *
 * @param arg
 * @return void*
 */
void* count_with_mutex(void* arg) {
    // s_lock.lock();
    for (int i = 0; i < 100000; i++) {
        s_lock.lock();
        s++;        
        s_lock.unlock();
    }
    // s_lock.unlock();
    return nullptr;
}

/**
 * @brief 用两个线程共同计数，每个线程计数100万次，我们预想的最终计数应该是200万：
 * 结果每次都不同，但都达不到200万
 * 原因：第二个线程读取了第一个线程没有处理完的结果，
 * 两个线程之间的结果相互覆盖。
 * race condition竞争条件：由于两个或者多个进程竞争使用不能被同时访问的资源，
 * 使得这些进程有可能因为时间上推进的先后原因而出现问题。
 * 通过加入mutex锁,可以保证对共享变量的操作不会被覆盖
 */
void test02() {
    pthread_t th1, th2;
    
    pthread_create(&th1, nullptr, count_with_mutex, nullptr);
    pthread_create(&th2, nullptr, count_with_mutex, nullptr);

    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);
    std::cout << "count is " << s << std::endl;
}

int main() {
    // test01();
    test02();

    return 0;
}