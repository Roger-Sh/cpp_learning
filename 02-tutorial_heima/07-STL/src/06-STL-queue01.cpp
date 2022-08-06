#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
**概念：**Queue是一种**先进先出**(First In First Out,FIFO)的数据结构，它有两个出口
队列容器允许从一端新增元素，从另一端移除元素
队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
队列中进数据称为 --- **入队**    `push`
队列中出数据称为 --- **出队**    `pop`


功能描述：栈容器常用的对外接口
构造函数：
- `queue<T> que;`                                 //queue采用模板类实现，queue对象的默认构造形式
- `queue(const queue &que);`            //拷贝构造函数

赋值操作：
- `queue& operator=(const queue &que);`           //重载等号操作符

数据存取：
- `push(elem);`                             //往队尾添加元素
- `pop();`                                      //从队头移除第一个元素
- `back();`                                    //返回最后一个元素
- `front(); `                                  //返回第一个元素

大小操作：
- `empty();`            //判断堆栈是否为空
- `size(); `              //返回栈的大小

总结：
- 入队   --- push
- 出队   --- pop
- 返回队头元素   --- front
- 返回队尾元素   --- back
- 判断队是否为空   --- empty
- 返回队列大小   --- size
*/

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};


void test01()
{
    // generate queue
    queue<Person> q;

    // prepare data
    Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);

    // add elements
    q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//队列不提供迭代器，更不支持随机访问	
    while(!q.empty())
    {
        // print element
        cout << "Queue head -- name: " << q.front().m_Name
             << "age: " << q.front().m_Age << endl;

        // print element
        cout << "Queue tail -- name: " << q.back().m_Name
             << "age: " << q.back().m_Age << endl;

        cout << endl;

        // pop element from queue head
        q.pop();
    }

    cout << "Queue size: " << q.size() << endl;
}

int main()
{
    test01();

    return 0;
}