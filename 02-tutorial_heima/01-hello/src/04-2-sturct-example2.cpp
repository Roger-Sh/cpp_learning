#include <iostream>

using namespace std;

/*
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
*/


struct hero
{
    string name;
    int age;
    string gender;
};


// sort hero by bubble algorithm
void sort_hero_bubble(struct hero hero_array[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 -i; j++)
        {
            if (hero_array[j].age > hero_array[j+1].age)
            {
                struct hero tmp = hero_array[j];
                hero_array[j] = hero_array[j+1];
                hero_array[j+1] = tmp;
            }
        }
    }
}

// print hero array
void print_hero_array(const struct hero hero_array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "Hero name: " << hero_array[i].name
            << " age: " << hero_array[i].age
            << " gender: " << hero_array[i].gender
            << endl;
    }
}


int main()
{
    struct hero heros[5] = 
    {
        {"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
    };

    int len = sizeof(heros) / sizeof(hero);

    sort_hero_bubble(heros, len);
    print_hero_array(heros, len);


    return 0;
}