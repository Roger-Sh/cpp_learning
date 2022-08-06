#include <iostream>
using namespace std;


#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>



/*
### 案例-评委打分

#### 3.4.1 案例描述
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

#### 3.4.2 实现步骤

1. 创建五名选手，放到vector中
2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3. sort算法对deque容器中分数排序，去除最高和最低分
4. deque容器遍历一遍，累加总分
5. 获取平均分

**总结：** 选取不同的容器操作数据，可以提升代码的效率
*/


class Person
{
public:
    Person(string name, int score)
    {
        this->m_name = name;
        this->m_score = score;
    }

public:
    string m_name;
    int m_score;
};


void create_person(vector<Person> &v)
{
    string name_seed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "Competitor";
        name += name_seed[i];

        int score = 0;

        Person p(name, score);

        // 将创建的person对象放入到容器中
        v.push_back(p);
    }   
}

void set_score(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 将所有评委的分数放到deque
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;   // 60 ~ 100
            d.push_back(score);
        }
        

        // 先排序，再删除max和min
        // sort 
        sort(d.begin(), d.end());

        // delete max and min
        d.pop_back();
        d.pop_front();

        // mean
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        int mean = sum / d.size();

        it->m_score = mean;
    }
    
}


void show_score(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name: " << it->m_name << " Mean: " << it->m_score << endl;
    }   
}

int main()
{
    cout << "Hello" << endl;

    // random seed
    srand( (unsigned int) time(NULL));

    // 5 competitor
    vector<Person> v;
    create_person(v);

    // score
    set_score(v);

    // show score
    show_score(v);

    return 0;

}