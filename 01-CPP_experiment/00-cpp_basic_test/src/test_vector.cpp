#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 打印 std::vector<int>
 *
 * @param vec
 * @param vec_name
 */
void PrintVecInt(const std::vector<int>& vec, const std::string& vec_name)
{
    std::cout << "\n=================\n";
    std::cout << vec_name << ": \n";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
    std::cout << "=================\n";
}

/**
 * @brief 打印 std::vector<std::string>
 *
 * @param vec
 * @param vec_name
 */
void PrintVecString(const std::vector<std::string>& vec, const std::string& vec_name)
{
    std::cout << "\n=================\n";
    std::cout << vec_name << ": \n";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
    std::cout << "=================\n";
}

/**
 * @brief 测试 vector 储存 int
 * 拷贝 vector 后，修改原 vector 的int, 不影响新的 vector
 */
void test01_vec_int()
{
    std::cout << "test01_vec_int: start\n";

    // 初始化 vec_1
    std::vector<int> vec_1;
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    PrintVecInt(vec_1, "vec_1");

    /**
     * @brief 通过构造器拷贝构造
     */

    // 用 vec_1 构造 vec_2
    std::vector<int> vec_2(vec_1);  // 构造器拷贝方法1
    // std::vector<int> vec_2(vec_1.begin(), vec_1.end());  // 构造器拷贝方法2
    PrintVecInt(vec_2, "vec_2");
    // 修改 vec_1 后，vec_2 不受影响
    vec_1[0] = 4;
    PrintVecInt(vec_1, "vec_1");
    PrintVecInt(vec_2, "vec_2");
    vec_1[0] = 1;

    /**
     * @brief 通过赋值拷贝
     *
     */

    // 将 vec_1 赋值给 vec_3
    std::vector<int> vec_3 = vec_1;
    PrintVecInt(vec_3, "vec_3");
    // 修改 vec_1 后，vec_3 不受影响
    vec_1[0] = 4;
    PrintVecInt(vec_1, "vec_1");
    PrintVecInt(vec_3, "vec_3");
    vec_1[0] = 1;

    /**
     * @brief 通过 assign 拷贝
     *
     */
    std::vector<int> vec_4;
    vec_4.assign(vec_1.begin(), vec_1.end());
    PrintVecInt(vec_4, "vec_4");
    // 修改 vec_1 后，vec_4 不受影响
    vec_1[0] = 4;
    PrintVecInt(vec_1, "vec_1");
    PrintVecInt(vec_4, "vec_4");
    vec_1[0] = 1;
}

/**
 * @brief 测试 存放 string 的 vector
 * 拷贝 vector 后，修改原 vector 的int, 不影响新的 vector
 */
void test02_vec_string()
{
    std::cout << "test02_vec_string: start\n";

    // 初始化 vec_1
    std::vector<std::string> vec_1;
    vec_1.push_back("string1");
    vec_1.push_back("string2");
    vec_1.push_back("string3");
    PrintVecString(vec_1, "vec_1");

    /**
     * @brief 通过构造器拷贝构造
     */

    // 用 vec_1 构造 vec_2
    std::vector<std::string> vec_2(vec_1);  // 构造器拷贝方法1
    // std::vector<int> vec_2(vec_1.begin(), vec_1.end());  // 构造器拷贝方法2
    PrintVecString(vec_2, "vec_2");
    // 修改 vec_1 后，vec_2 不受影响
    vec_1[0] = "string4";
    PrintVecString(vec_1, "vec_1");
    PrintVecString(vec_2, "vec_2");
    vec_1[0] = "string1";

    /**
     * @brief 通过赋值拷贝
     *
     */

    // 将 vec_1 赋值给 vec_3
    std::vector<std::string> vec_3 = vec_1;
    PrintVecString(vec_3, "vec_3");
    // 修改 vec_1 后，vec_3 不受影响
    vec_1[0] = "string4";
    PrintVecString(vec_1, "vec_1");
    PrintVecString(vec_3, "vec_3");
    vec_1[0] = "string1";

    /**
     * @brief 通过 assign 拷贝
     *
     */
    std::vector<std::string> vec_4;
    vec_4.assign(vec_1.begin(), vec_1.end());
    PrintVecString(vec_4, "vec_4");
    // 修改 vec_1 后，vec_4 不受影响
    vec_1[0] = "string4";
    PrintVecString(vec_1, "vec_1");
    PrintVecString(vec_4, "vec_4");
    vec_1[0] = "string1";
}

class Student
{
public:
    int id_;
    std::string name_;
    std::vector<int> scores_vec_;
    char hobby_[50];
    int* age_shallow_;
    int* age_deep_;

    Student(const int id, const std::string name) : id_(id), name_(name)
    {
        strcpy(this->hobby_, "");

        this->age_shallow_ = new int(-1);
        this->age_deep_ = new int(-1);
    }

    Student(const Student& stu) : id_(stu.id_), name_(stu.name_), scores_vec_(stu.scores_vec_)
    {
        std::cout << "using Student(const Student& stu)\n";

        strcpy(this->hobby_, stu.hobby_);

        // 浅拷贝，直接复制了地址
        this->age_shallow_ = stu.age_shallow_;

        // 深拷贝，拷贝值
        this->age_deep_ = new int;
        *this->age_deep_ = *stu.age_deep_;
    }

    void operator=(const Student& stu)
    {
        std::cout << "using void operator=(const Student& stu)\n";
        this->id_ = stu.id_;
        this->name_ = stu.name_;
        this->scores_vec_ = stu.scores_vec_;

        strcpy(this->hobby_, stu.hobby_);

        // 浅拷贝，直接复制了地址
        this->age_shallow_ = stu.age_shallow_;

        // 深拷贝，拷贝值
        this->age_deep_ = new int;
        *this->age_deep_ = *stu.age_deep_;
    }

    ~Student()
    {
        // 非法：浅拷贝造成双重释放，不能 delete
        // delete this->age_shallow_;

        // 合法：深拷贝不会造成双重释放，可以 delete
        std::cout << "free: " << this->name_ << "\n";
        delete this->age_deep_;
        // if (this->age_deep_ != NULL)
        // {
        //     delete this->age_deep_;
        //     this->age_deep_ = NULL;
        // }
    }

    void Show()
    {
        std::cout << "id_: " << this->id_ << "\n";
        std::cout << "name_: " << this->name_ << "\n";
        for (size_t i = 0; i < this->scores_vec_.size(); i++)
        {
            std::cout << "this->scores_vec_[" << i << "]: " << this->scores_vec_[i] << "\n";
        }
        std::cout << "hobby: " << this->hobby_ << "\n";

        std::cout << "age_shallow_: " << *this->age_shallow_ << "\n";
        std::cout << "age_deep_: " << *this->age_deep_ << "\n";
    }

    void ShowDeep()
    {
        std::cout << "static_cast<void *>(this->age_deep_): " << static_cast<void*>(this->age_deep_) << "\n";
    }

    void ShowShallow()
    {
        std::cout << "static_cast<void *>(this->age_shallow): " << static_cast<void*>(this->age_shallow_) << "\n";
    }
};

/**
 * @brief 测试 vector 中的对象是否会互相影响
 *
 */
void test03_vec_class()
{
    Student stu1(1, "stu1");
    Student stu2(2, "stu2");
    Student stu3(3, "stu3");

    std::vector<Student> stu_vec1;
    stu_vec1.push_back(stu1);
    stu_vec1.push_back(stu2);
    stu_vec1.push_back(stu3);

    // 拷贝 stu_vec1 到 stu_vec2
    std::vector<Student> stu_vec2;
    stu_vec2 = stu_vec1;
    // std::vector<Student> stu_vec2(stu_vec1);
    // stu_vec2.assign(stu_vec1.begin(), stu_vec1.end());
    for (size_t i = 0; i < stu_vec2.size(); i++)
    {
        stu_vec2[i].Show();
    }

    // 修改 stu_vec1 的内容，不管用哪种拷贝方式，都不会影响到 stu_vec2
    stu_vec1[0].id_ = 10;
    for (size_t i = 0; i < stu_vec2.size(); i++)
    {
        stu_vec2[i].Show();
    }

    // class 里的 vector 拷贝后互相独立，不受影响
    stu_vec1[0].scores_vec_.clear();
    stu_vec1[0].scores_vec_.push_back(90);
    stu_vec1[0].scores_vec_.push_back(91);
    for (size_t i = 0; i < stu_vec2.size(); i++)
    {
        stu_vec2[i].Show();
    }
    stu_vec2 = stu_vec1;
    for (size_t i = 0; i < stu_vec2.size(); i++)
    {
        stu_vec2[i].Show();
    }

    // 如果 class 中有字符串数组，需要实现深拷贝，互相之间是独立的
    strcpy(stu_vec1[0].hobby_, "basketball");
    stu_vec1[0].Show();
    stu_vec2 = stu_vec1;
    for (size_t i = 0; i < stu_vec2.size(); i++)
    {
        stu_vec2[i].Show();
    }

    // 浅拷贝的测试，原 vector 中的元素中指针内容修改后，新 vector 也会同时被修改，因为共享了同一个指针
    stu_vec2[0].Show();  // age_shallow_: -1
    *stu_vec1[0].age_shallow_ = 10;
    stu_vec2[0].Show();  // age_shallow_: 10
    stu_vec2 = stu_vec1;
    stu_vec2[0].Show();  // age_shallow_ : 10

    // 深拷贝的测试，原 vector 与 新 vector 互相独立，元素中的成员指针不会被共享，只有在拷贝时值才会被拷贝
    std::vector<Student> stu_vec3 = stu_vec1;
    stu_vec3[0].Show();
    *stu_vec1[0].age_deep_ = 50;
    stu_vec3[0].Show();
    stu_vec3 = stu_vec1;
    stu_vec3[0].Show();

    for (size_t i = 0; i < stu_vec1.size(); i++)
    {
        stu_vec1[i].ShowDeep();
    }
    for (size_t i = 0; i < stu_vec2.size(); i++)
    {
        stu_vec2[i].ShowDeep();
    }
    for (size_t i = 0; i < stu_vec3.size(); i++)
    {
        stu_vec3[i].ShowDeep();
    }

    for (size_t i = 0; i < stu_vec1.size(); i++)
    {
        stu_vec1[i].ShowShallow();
    }
    for (size_t i = 0; i < stu_vec2.size(); i++)
    {
        stu_vec2[i].ShowShallow();
    }
    for (size_t i = 0; i < stu_vec3.size(); i++)
    {
        stu_vec3[i].ShowShallow();
    }

    /**
     * @brief 测试 vector 赋值时，通过调用 class 的什么方法来赋值
     */

    // using Student(const Student& stu)
    std::vector<Student> stu_vec4(stu_vec3);
    // using void operator=(const Student& stu)
    stu_vec4 = stu_vec3;
    // using Student(const Student& stu)
    std::vector<Student> stu_vec5;
    stu_vec5 = stu_vec3;
    // using Student(const Student& stu)
    std::vector<Student> stu_vec6;
    stu_vec6.assign(stu_vec1.begin(), stu_vec1.end());

    std::cout << "=============\n";
    std::vector<Student> stu_vec7(stu_vec1);  // using Student(const Student& stu)
    std::cout << "=============\n";
    stu_vec1.push_back(Student(stu1));  // 增加一个新的元素 using Student(const Student& stu)
    std::cout << "=============\n";     // using Student(const Student& stu)
    stu_vec7 = stu_vec1;                // 更新 stu_vec7

    std::cout << "test03_vec_class: finish"
              << "\n";
}

/**
 * @brief 测试 vector
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const* argv[])
{
    test01_vec_int();
    test02_vec_string();
    test03_vec_class();

    return 0;
}
