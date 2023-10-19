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
 *
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
 *
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

    return 0;
}
