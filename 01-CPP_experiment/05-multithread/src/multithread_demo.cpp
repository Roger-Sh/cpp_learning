#include <pthread.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

/**
 * @brief a func run in another thread
 *
 * @param ptr
 * @return void*
 */
void* thread_func(void* ptr) {
    for (int i = 0; i < 3; i++) {
        sleep(1);
        std::cout << "This is a pthread.\n";
    }
    return 0;
}

/**
 * @brief 被线程调用的函数的输入形参是void*，即任意形式的指针
 * 在使用的时候，当然要把void*强制转换为其他类型的指针，这里是char*类型(char数组)
 * 
 * @param a 
 * @return void* 
 */
void* func1(void* a)
{
    char* chptr;
    chptr = (char*) a;
    for (int i = 0; i < 5; ++i)
    {
        sleep(1);
        std::stringstream ss;
        ss << chptr << ": " << i << std::endl;
        std::cout << ss.str();
    }
}

/**
 * @brief 测试创建一个线程
 * 
 */
void test01() {
// 线程的标识符
    pthread_t id;

    // pthread_create：创建线程
    // 输入：
    //  第一个参数为指向线程标识符的指针
    //  第二个参数用来设置线程属性
    //  第三个参数是线程运行函数的起始地址
    //  最后一个参数是运行函数的参数
    // 输出：
    //  0-表示创建成功
    //  EAGAIN-系统限制创建新的线程，例如线程数目过多了
    //  EINVAL-第二个参数代表的线程属性值非法
    int ret = pthread_create(&id, NULL, thread_func, NULL);
    if (ret) {
        std::cout << "Create pthread error!" << std::endl;
        return;
    }

    // main loop
    for (int i = 0; i < 3; i++) {
        std::cout << "This is the main process.\n";
        sleep(1);
    }

    // pthread_join: 等待一个线程的结束
    // 输入：
    //  第一个参数为被等待的线程标识符
    //  第二个参数为一个用户定义的指针，存储被等待线程的返回值
    // 这个函数是一个线程阻塞的函数，调用它的函数将一直等待到被等待的线程结束为止，当函数返回时，被等待线程的资源被收回。
    pthread_join(id, NULL);

    // main loop
    for (int i = 0; i < 3; i++) {
        std::cout << "This is the main 2.process.\n";
        sleep(1);
    }
}

void test02() {
    // create threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, nullptr, thread_func, nullptr);
    pthread_create(&thread2, nullptr, thread_func, nullptr);
    
    // main loop
    for (int i = 0; i < 3; i++) {
        std::cout << "This is the main process.\n";
        sleep(1);
    }

    // wait for threads
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
}

void test03() {
    pthread_t thread1, thread2;
    char* str1 = "thread1";
    char* str2 = "thread2";

    // 传入参数是两个char数组，char指针类型
    pthread_create(&thread1, nullptr, func1, str1);
    pthread_create(&thread2, nullptr, func1, str2);
    
    // 也可以是这样：
    // pthread_create(&thread1, nullptr, func1, (void*)"thread1");
    // 显式or隐式，传进去的都是void*类型，需要在函数内进行强制转换
    
    std::cout << "Hello, World!\n";
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
}



/**
 * @brief main
 *
 * @return int
 */
int main() {
    
    // test01();
    // test02();
    test03();

    return 0;
}
