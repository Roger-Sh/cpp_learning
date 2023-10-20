#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 测试 const 的基础用法
 *
 */
void test01_const_basic()
{
    /**
     * @brief 针对普通变量
     *
     */

    // 定义时需要初始化
    const int a = 5;
    const std::string name = "xiaoming";

    // 只读，不可改动
    // a = 10;             // error
    // name = "xiaowang";  // error

    /**
     * @brief 针对指针
     * 技巧：const 优先修饰其左侧量，如果左侧没有，则修饰右侧的量
     *      const int *，修饰 int，int 值不能更改，* 指针可以更改
     *      int const *，修饰 int，int 值不能更改，* 指针可以更改
     *      int * const，修饰 *，* 指针不能更改，int 值可以更改
     */

    // 内容 const 方式1，使用 cont int*，指针可以修改，内容不可以修改，不需要初始化
    int a2 = 5;
    const int *c;
    c = &a2;                  // 合法：cont int*，指针可以修改
    std::cout << c << "\n";   // 0x7ffc6bb44220
    std::cout << *c << "\n";  // 5
    a2 = 6;                   // 合法，通过修改指针对应原地址的值，修改内容
    std::cout << c << "\n";   // 0x7ffc6bb44220
    std::cout << *c << "\n";  // 6
    int a3 = 7;
    c = &a3;                  // 合法：cont int*，指针可以修改
    std::cout << c << "\n";   // 0x7ffc6bb44224
    std::cout << *c << "\n";  // 7
    // *c = 8;                // 非法：cont int*，指针可以修改，内容不可以修改

    // 内容 const 方式2
    int const *f;
    int e = 1000;
    f = &e;                   // 合法：指针可以修改
    std::cout << f << "\n";   // 0x7fff0b9e9508
    std::cout << *f << "\n";  // 1000
    // *f = 1001;             // 非法：内容不可以修改
    e = 1001;                 // 合法，通过修改原变量的值，修改当前指针指向的值
    std::cout << f << "\n";   // 0x7fff0b9e9508
    std::cout << *f << "\n";  // 1001
    int e2 = 1002;
    f = &e2;                  // 合法：指针可以修改
    std::cout << f << "\n";   // 0x7fff0b9e950c
    std::cout << *f << "\n";  // 1002

    // 指针 const，使用 int *const, 指针不能修改，内容可以修改，需要初始化
    int b = 100;
    int *const d = &b;        // 创建时需要初始化
    std::cout << d << "\n";   // 0x7ffc6b6bd294
    std::cout << *d << "\n";  // 100
    int b2 = 200;
    // d = &b2;               // 非法：int *const，不能修改指针
    *d = 101;                 // 合法：int *const，可以修改内容
    std::cout << d << "\n";   // 0x7ffc6b6bd294
    std::cout << *d << "\n";  // 101

    // 指针与内容 const，指针和内容都不能修改，需要初始化
    int h = 10000;
    const int *const g = &h;
    std::cout << g << "\n";   // 0x7ffe4d21e3e4
    std::cout << *g << "\n";  // 10000
    int h2 = 20000;
    // g = &h2;               // 非法：指针不能修改
    // *g = 20001;            // 非法：内容不能修改
    h = 10001;                // 合法：通过修改原变量的值来修改当前指针指向的值
    std::cout << g << "\n";   // 0x7ffe4d21e3e4
    std::cout << *g << "\n";  // 10001
}

/**
 * @brief const 修饰入参的值
 *
 * @param a
 */
void test02_func1(const int a)
{
    std::cout << "test02_func1: \n";
    std::cout << a << "\n";  // 10
    // a++;                  // 非法：a 无法被修改
}

/**
 * @brief const 修饰入参的指针
 *
 * @param a
 */
void test02_func2(int *const a)
{
    std::cout << "test02_func2: \n";
    std::cout << a << "\n";   // 0x7fffdaf53064
    std::cout << *a << "\n";  // 10
    int *b = new int;
    *b = 20;
    // a = b;                 // 非法：指针无法被修改
    *a = *b;                  // 指针的内容可以被修改
    std::cout << a << "\n";   // 0x7fffdaf53064
    std::cout << *a << "\n";  // 20

    delete b;
}

/**
 * @brief const 修饰入参指针的内容
 *
 * @param a
 */
void test02_func3(const int *a)
{
    std::cout << "test02_func3: \n";
    std::cout << a << "\n";   // 0x7fffdaf53064
    std::cout << *a << "\n";  // 20
    // *a = 20;               // 非法：指针内容无法被修改
    int *b = new int;
    *b = 30;
    a = b;                    // 指针可以被修改
    std::cout << a << "\n";   // 0x5607af99a280
    std::cout << *a << "\n";  // 20

    delete b;
}

/**
 * @brief const 修饰出参的内容，指针可以修改，内容不能修改
 *
 * @param a
 * @param b
 * @return int*
 */
const int *test02_func4(int a, int b)
{
    // 非法：warning: address of local variable ‘c’ returned，会得到野指针
    // int c = a + b;
    // return &c;

    int *c = new int;
    *c = a + b;

    std::cout << "test02_func4: \n";
    std::cout << c << "\n";   // 0x55c6ec18e280
    std::cout << *c << "\n";  // 3

    // 这里如果删除了c指针，返回的c就成了野指针，会被覆盖
    // delete c;
    // int *d = new int; // 重新创建一个指针后，会把原来的野指针的内容覆盖掉
    return c;
}

/**
 * @brief const 修饰出参指针，指针内容可以修改，指针不能修改
 * 没有实际应用场景？
 * @param a
 * @param b
 * @return int* const
 */
int *const test02_func5(int a, int b)
{
    int *c = new int;
    *c = a + b;

    std::cout << "test02_func5: \n";
    std::cout << *c << "\n";  // 3

    return c;
}

/**
 * @brief 测试 const 传递参数
 *
 */
void test02_const_argument()
{
    // 测试 const 修饰入参普通参数
    test02_func1(10);
    int a = 10;

    // 测试 const 修饰入参指针参数的指针
    test02_func2(&a);
    std::cout << a << "\n";  // 20，被 test02_func2 中修改过内容

    // 测试 const 修饰入参指针参数的内容
    test02_func3(&a);
    std::cout << a << "\n";  // 20，test02_func3 只能对入参修改指针，无法修改内容

    // 测试 const 修饰出参指针参数的内容
    const int *c = test02_func4(1, 2);
    std::cout << c << "\n";   // 0x55c6ec18e280
    std::cout << *c << "\n";  // 3
    // *c = 10; // 非法：指针内容无法被修改
    int d = 20;
    c = &d;  // 合法：指针可以被修改

    const int *e = test02_func5(1, 2);
    std::cout << *e << "\n";  // 3
    // *e = 10; // 非法，指针内容无法被修改
    int f = 20;
    e = &f;
    std::cout << *e << "\n";  // 20
}

/**
 * @brief class Student，用于测试
 *
 */
class Student
{
public:
    const std::string name_;
    const int id_;
    int age_;
    std::string address_;
    int *score_;
    std::vector<int> scores_vec;
    char homework_[10];
    char *hobby_;  // 不分配内存的情况下与 std::vector 冲突

    /**
     * @brief Construct a new Student object
     *
     * @param name
     * @param id
     * @param age
     */
    Student(const std::string name, const int id, const int age) : name_(name), id_(id), age_(age)
    {
        this->score_ = new int;

        this->hobby_ = new char[10];
    }

    /**
     * @brief Construct a new Student object
     * deep copy
     * @param stu
     */
    Student(const Student &stu) : name_(stu.name_), id_(stu.id_), age_(stu.age_)
    {
        // 非法：不能直接复制不同对象的指针，会导致多次释放
        // this->score_ = stu.score_;

        // 成员指针指向的内容，需要实现深拷贝
        this->score_ = new int;
        *this->score_ = *stu.score_;
        this->hobby_ = new char[10];
    }

    ~Student()
    {
        delete this->score_;
    }

    /**
     * @brief for non-const instance
     *
     */
    void Show()
    {
        std::cout << "from non-const show\n";
        std::cout << "name_: " << this->name_ << "\n";
        std::cout << "id_: " << this->id_ << "\n";
        std::cout << "age_: " << this->age_ << "\n";
    }

    /**
     * @brief for const instance
     *
     */
    void Show() const
    {
        std::cout << "from const show\n";
        std::cout << "name_: " << this->name_ << "\n";
        std::cout << "id_: " << this->id_ << "\n";
        std::cout << "age_: " << this->age_ << "\n";
    }

    void ShowScores() const
    {
        for (size_t i = 0; i < this->scores_vec.size(); i++)
        {
            std::cout << "this->scores_vec[" << i << "]: " << this->scores_vec[i] << "\n";
        }
    }
};

/**
 * @brief 测试 const 对象
 * 1. 对象成员变量本身有 const 修饰，不能被修改
 * 2. 对象如果被 const 修饰，所有成员变量都不能被修改，同时调用的成员函数需要被 const 修饰
 * 3. 对象如果被 const 修饰，所有成员变量都不能被修改，但对象的成员变量如果是指针，指针指向的内容可以被修改
 */
void test03_const_class()
{
    // 普通对象
    Student stu1("stu1", 1, 10);
    stu1.Show();
    stu1.age_ = 12;                   // 没有const修饰的成员变量，可以被修改
    stu1.address_ = "1. str. nr. 1";  // 没有const修饰的成员变量，可以被修改
    // stu1.name_ = "stu2";           // 被 const 修饰，不能被修改
    *stu1.score_ = 10;
    std::cout << "stu1.score: " << *stu1.score_ << "\n";
    strcpy(stu1.homework_, "math");
    std::cout << "stu1.homework: " << stu1.homework_ << "\n";
    std::cout << "static_cast<void *>(stu1.hobby_): " << static_cast<void *>(stu1.hobby_) << "\n";  // 0x555fc7a73048
    strcpy(stu1.hobby_, "music");                                                                   // 不会修改指针本身
    std::cout << "stu1.hobby: " << stu1.hobby_ << "\n";                                             // stu1.hobby: music
    std::cout << "static_cast<void *>(stu1.hobby_): " << static_cast<void *>(stu1.hobby_) << "\n";  // 0x555fc7a73048

    // 成员指针析构时会被删除，当更换成员指针时，原指针分配的内存需要先被释放，否则会成为野指针
    delete stu1.score_;
    int *score = new int;
    *score = 20;
    stu1.score_ = score;

    // const 对象，对象的成员变量也会被 const 修饰
    const Student stu2("stu2", 1, 10);
    // stu2.age_ = 14;                  // 被const修饰的对象的成员变量不能被修改
    // stu2.address_ = "1. str. nr. 2"; // 被const修饰的对象的成员变量不能被修改
    *stu2.score_ = 20;  // 对象被const修饰，对象成员变量不能被修改，但对象的成员变量如果是指针，指针指向的内容可以被修改
    std::cout << "stu2.score: " << *stu2.score_ << "\n";
    stu2.Show();
    // strcpy(stu2.homework_, "english"); // 被const修饰的对象的成员变量不能被修改
    // strcpy(stu2.hobby_, "basketball"); // 被const修饰的对象的成员变量不能被修改
    // std::cout << "stu2.hobby: " << stu2.hobby_ << "\n";

    // const 对象的拷贝构造
    const Student stu3(stu2);
    stu3.Show();
}

/**
 * @brief 测试 const 修饰 class 中的 vector
 *
 */
void test04_const_class_vec()
{
    std::cout << "test04_const_class_vec: start\n";

    Student stu1("stu1", 1, 10);
    stu1.scores_vec.push_back(90);
    stu1.scores_vec.push_back(91);
    stu1.scores_vec.push_back(92);
    stu1.ShowScores();
    std::vector<int> scores_vec;
    scores_vec.push_back(80);
    scores_vec.push_back(81);
    scores_vec.push_back(82);
    stu1.scores_vec = scores_vec;
    stu1.ShowScores();

    // const 修饰 vector时，vector 本身以及内容都被修饰
    const Student stu2("stu2", 2, 12);
    // stu2.scores_vec[0] = 63;         // const 修饰 对象时，成员vector内容被修饰
    // stu2.scores_vec.push_back(70);   // const 修饰 对象时，成员vector无法被添加新的内容
    // stu2.scores_vec.push_back(71);
    // stu2.scores_vec.push_back(72);
    stu2.ShowScores();
    // stu2.scores_vec = scores_vec;    // const 修饰 对象时，成员vector本身被修饰
}

int main()
{
    test01_const_basic();
    test02_const_argument();
    test03_const_class();
    test04_const_class_vec();
    return 0;
}