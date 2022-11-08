#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::string> a_group;
    a_group.push_back("单维朴");
    a_group.push_back("郑思仪");
    a_group.push_back("安之建");
    a_group.push_back("杨风原");
    a_group.push_back("杨奎");
    a_group.push_back("刘玉");
    a_group.push_back("刘龙");

    std::random_shuffle(a_group.begin(), a_group.end());
    std::cout << "热身赛顺序: " << std::endl;
    for (size_t i = 0; i < a_group.size(); i++)
    {
        std::cout << i << ": " << a_group[i] << std::endl;
    }

    std::random_shuffle(a_group.begin(), a_group.end());
    std::cout << "积分赛顺序: " << std::endl;
    for (size_t i = 0; i < a_group.size(); i++)
    {
        std::cout << i << ": " << a_group[i] << std::endl;
    }
    
}