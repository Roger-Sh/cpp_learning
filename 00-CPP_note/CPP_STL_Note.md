# CPP_STL_Note



## STL 基本概念

- STL - Standard Template Library
- STL 分为
  - 容器，container
    - 序列式容器
      - 强调排序， 每个元素有固定位置
    - 关联式容器
      - 强调关系， 没有严格的顺序
    - 常用数据结构
      - vector 向量
      - list 列表
      - tree 树
      - stack 栈
      - deque 双端数组
      - queue 队列
      - set 堆
      - map 
      - ...
  - 算法，algorithm
    - 质变算法
      - 运算中会更改元素内容， 拷贝， 替换， 删除等
    - 非质变算法
      - 查找， 计数，遍历，寻找极值等
    - 常见算法
      - sort
      - find
      - copy
      - for_each
      - ...
  - 迭代器，iterator
    - 容器和算法之间的胶合器
    - 依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式
  - 仿函数
    - 行为类似函数， 算法的策略
  - 适配器
    - 修饰容器或仿函数或迭代器接口的东西
  - 空间配置器
    - 空间的配置与管理



## String

### string 构造函数

```c++
// 创建空的字符串
std::string str;	

// 使用字符串s初始化
const char* str = "hello world";
std::string s2(str); 

// 拷贝初始化
std::string s3(s2); 

// 使用n个字符c初始化
std::string s4(10, 'a');

```

### string 赋值

```c++
// operator =
string& operator=(const char* s);		  // char* 字符串
string& operator=(const string &s);		// string 字符串
string& operator=(char c);						// char 字符

// method assign()
string& assign(const char *s);				// char* 字符串
string& assign(const char *s, int n);  // 字符串s前n个字符
string& assign(const string &s);	// 字符串s
string& assign(int n, char c);	// n个字符c
```

### string 拼接

```c++
// operator +=
string& operator+=(const char* str);
string& operator+=(const char c);
string& operator+=(const string& str);

// method append()
string& append(const char *s);
string& append(const char *s, int n);
string& append(const string &s);
string& append(const string &s, int pos, int n);
```

### stirng 查找与替换

```c++
// method find() 查找 *****************************
//查找str第一次出现位置,从pos开始查找
int find(const string& str, int pos = 0) const;
 //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;
//从pos位置查找s的前n个字符第一次位置
int find(const char* s, int pos, int n) const;
 //查找字符c第一次出现位置
int find(const char c, int pos = 0) const; 

// method rfind()  反向查找****************************
 //查找str最后一次位置,从pos开始查找
int rfind(const string& str, int pos = npos) const;
//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; 
//从pos查找s的前n个字符最后一次位置
int rfind(const char* s, int pos, int n) const;     
//查找字符c最后一次出现位置
int rfind(const char c, int pos = 0) const;     

// method replace() 替换 ******************************
//替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const string& str); 
//替换从pos开始的n个字符为字符串s
string& replace(int pos, int n,const char* s);             

```

### string 比较

```c++
// method compare()
// return 等于0，大于1， 小于-1
int compare(const string &s) const;      //与字符串s比较
int compare(const char *s) const;     //与字符串s比较
```

### string 字符存取

```c++
char& operator[](int n);     //通过[]方式取字符
char& at(int n);                     //通过at方法获取字符
```

### string 插入和删除

```c++
string& insert(int pos, const char* s);                 //插入字符串
string& insert(int pos, const string& str);         //插入字符串
string& insert(int pos, int n, char c);                //在指定位置插入n个字符c
string& erase(int pos, int n = npos);                    //删除从Pos开始的n个字符 
```

### string 子串

```c++
string substr(int pos = 0, int n = npos) const;   //返回由pos开始的n个字符组成的字符串
```







## Vector

### Vector 构造

```c++
vector<T> v;                		     //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());       //将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);                            //构造函数将n个elem拷贝给本身。
vector(const vector &vec);         //拷贝构造函数。
```



### Vector 赋值

```c++
vector& operator=(const vector &vec);	//重载等号操作符
assign(beg, end);       //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);        //将n个elem拷贝赋值给本身。
```



### Vector 容量与大小

```c++
//判断容器是否为空
empty();                      

//容器的容量
capacity();                   

 //返回容器中元素的个数
size();                             

//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num);             

//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
 //如果容器变短，则末尾超出容器长度的元素被删除
resize(int num, elem);`  
```



### Vector 插入与删除

```c++
push_back(ele);                                         //尾部插入元素ele
pop_back();                                                //删除最后一个元素
insert(const_iterator pos, ele);        //迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);                     //删除迭代器指向的元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
clear();                                                        //删除容器中所有元素
```



### Vector 数据存取

```c++
at(int idx);     //返回索引idx所指的数据
operator[];       //返回索引idx所指的数据
front();            //返回容器中第一个数据元素
back();              //返回容器中最后一个数据元素
```



### Vector 互换容器

```c++
swap(vec);  // 将vec与本身的元素互换
```



### Vector 预留空间

```c++
reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。
```



## Deque

### Deque 特点

- 双端数组，可以对头端进行插入删除操作
- Deque 与 Vector 对比
  - vector对于头部的插入删除效率低，数据量越大，效率越低
  - deque相对而言，对头部的插入删除速度回比vector快
  - vector访问元素时的速度会比deque快,这和两者内部实现有关
  - deque容器的迭代器也是支持随机访问的
- Deque 原理
  - deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据，中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

### Deque 构造

```c++
deque<T> deqT;                      //默认构造形式
deque(beg, end);                  //构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);                    //构造函数将n个elem拷贝给本身。
deque(const deque &deq);   //拷贝构造函数
```



### Deque 赋值

```c++
deque& operator=(const deque &deq);          //重载等号操作符
assign(beg, end);                                           //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);                                             //将n个elem拷贝赋值给本身。
```



### Deque 大小

```c++
//判断容器是否为空
deque.empty();                     

//返回容器中元素的个数
deque.size();                        

//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num);               

//重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem);     
```



### Deque 插入与删除

- 两端插入操作

  ```c++
  push_back(elem);          //在容器尾部添加一个数据
  push_front(elem);        //在容器头部插入一个数据
  pop_back();                   //删除容器最后一个数据
  pop_front();                 //删除容器第一个数据
  ```

  

- 指定位置操作

  ```c++
  //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
  insert(pos,elem);         
  //在pos位置插入n个elem数据，无返回值。
  insert(pos,n,elem);     
   //在pos位置插入[beg,end)区间的数据，无返回值。
  insert(pos,beg,end);   
   //清空容器的所有数据
  clear();                          
   //删除[beg,end)区间的数据，返回下一个数据的位置。
  erase(beg,end);            
   //删除pos位置的数据，返回下一个数据的位置。
  erase(pos);                   
  ```

  

### Deque 数据存取

```c++
at(int idx);     	//返回索引idx所指的数据
operator[];      	//返回索引idx所指的数据
front();    		//返回容器中第一个数据元素
back();        		//返回容器中最后一个数据元素
```



### Deque 排序

```c++
sort(iterator beg, iterator end)  //对beg和end区间内元素进行排序
```



## Stack

### Stack 特点

stack是一种**先进后出**(First In Last Out,FILO)的数据结构，它只有一个出口

栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为

栈中进入数据称为  --- **入栈**  `push`

栈中弹出数据称为  --- **出栈**  `pop`



### Stack 构造

```c++
// 默认构造函数
stack<T> stk;

// 拷贝构造函数
stack(const stack &stk);
```



### Stack 赋值

```c++
stack& operator=(const stack &stk);
```



### Stack 存取

```c++
// 栈顶添加元素
stk.push(element);

// 栈顶移除元素
stk.pop();

// 返回栈顶元素
stk.top();
```



### Stack 大小

```c++
stk.empty();
stk.size();
```

 







## Queue

### Queue 特点

Queue是一种**先进先出**(First In First Out,FIFO)的数据结构，它有两个出口

队列容器允许从一端新增元素，从另一端移除元素

队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为

队列中进数据称为 --- **入队**    `push`

队列中出数据称为 --- **出队**    `pop`



### Queue 构造

```c++
// 默认构造
queue<T> que;

// 拷贝构造
queue(const queue &que);
```



### Queue 赋值

```c++
queue& operator=(const queue &que);
```



### Queue 存取

```c++
// 队尾添加元素
que.push(elem);

// 队头移除元素
que.pop();

// 获取队尾元素
que.back();

// 获取队头元素
que.front();
```



### Queue 大小

```c++
que.empty();
que.size();
```



## List

### List 特点

-   **功能：**将数据进行链式存储

-   **链表**（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

    -   链表的组成：链表由一系列**结点**组成


    -   结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**


    -   STL中的链表是一个双向循环链表

-   List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

-   list的优点：

    * 采用动态存储分配，不会造成内存浪费和溢出

    * 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素


-   list的缺点：

    * 链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大





### List 构造

```c++
// list采用采用模板类实现,对象的默认构造形式
list<T> lst;

// 构造函数将[beg, end)区间中的元素拷贝给本身
list(beg,end);

// 构造函数将n个elem拷贝给本身
list(n,elem);

// 拷贝构造函数。
list(const list &lst);
```



### List 赋值和交换

```c++
// 将[beg, end)区间中的数据拷贝赋值给本身。
assign(beg, end);

// 将n个elem拷贝赋值给本身。
assign(n, elem);

// 重载等号操作符
list& operator=(const list &lst);

// 将lst与本身的元素互换。
swap(lst);
```



### List 大小

```c++
// 返回容器中元素的个数
size();

// 判断容器是否为空
empty();

// 重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
// 如果容器变短，则末尾超出容器长度的元素被删除。
resize(num);

// 重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
// 如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);

```



### List 插入和删除

```c++
// 在容器尾部加入一个元素
push_back(elem);

// 删除容器中最后一个元素
pop_back();

// 在容器开头插入一个元素
push_front(elem);

// 从容器开头移除第一个元素
pop_front();

// 在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,elem);

// 在pos位置插入n个elem数据，无返回值。
insert(pos,n,elem);

// 在pos位置插入[beg,end)区间的数据，无返回值。
insert(pos,beg,end);

// 移除容器的所有数据
clear();

// 删除[beg,end)区间的数据，返回下一个数据的位置。
erase(beg,end);

// 删除pos位置的数据，返回下一个数据的位置。
erase(pos);

// 删除容器中所有与elem值匹配的元素。
remove(elem);
```



### List 数据存取

```c++
// 获取第一个元素
front();

// 获取最后一个元素
back();
```



### List 反转和排序

```c++
// 反转链表
reerse();

// 排序, 默认从小到达
// 可以指定排序规则
// 自定义数据类型必须指定排序规则
sort();
```



```c++
/**
自定义排序
**/
#include <list>
#include <string>
class Person 
{
public:
	Person(string name, int age , int height) 
    {
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

public:
	string m_Name;  //姓名
	int m_Age;      //年龄
	int m_Height;   //身高
};


bool ComparePerson(Person& p1, Person& p2) 
{
	if (p1.m_Age == p2.m_Age) 
    {
		return p1.m_Height  > p2.m_Height;
	}
	else
	{
		return  p1.m_Age < p2.m_Age;
	}

}

void test01() {

	list<Person> L;

	Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) 
    {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age 
              << " 身高： " << it->m_Height << endl;
	}

	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //排序

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) 
    {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age 
              << " 身高： " << it->m_Height << endl;
	}
}

int main() 
{
	test01();

	system("pause");

	return 0;
}
```



## Set/Multiset

### Set 特点

-   set/multiset属于**关联式容器**，底层结构是用**二叉树**实现。

-   所有元素都会在插入时自动被排序

-   **set和multiset区别**：

    * set不允许容器中有重复的元素

    * multiset允许容器中有重复的元素

        

### Set 构造与赋值

```c++
// 默认构造函数：
set<T> st;

// 拷贝构造函数
set(const set &st);

// 重载等号操作符
set& operator=(const set &st);
```



### Set 大小与交换

```c++
// 返回容器中元素的数目
size();

// 判断容器是否为空
empty();

// 交换两个集合容器
swap(st);
```



### Set 插入与删除

```c++
// 在容器中插入元素。
insert(elem);

// 清除所有元素
clear();

// 删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(pos);

// 删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(beg, end);

// 删除容器中值为elem的元素。
erase(elem);
```



### Set 查找与统计

```c++
// 查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
find(key);

// 统计key的元素个数
count(key);
```



### Set 与Multiset 区别

* set不可以插入重复数据，而multiset可以
* set插入数据的同时会返回插入结果，表示插入是否成功
* multiset不会检测数据，因此可以插入重复数据



### Set 排序 

-   set容器默认排序规则为从小到大
-   利用仿函数，可以改变排序规则

```c++
/**
set使用自定义排序规则
**/

#include <set>

class MyCompare 
{
public:
	bool operator()(int v1, int v2) 
    {
		return v1 > v2;
	}
};

void test01() 
{    
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

	//默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) 
    {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则
	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) 
    {
		cout << *it << " ";
	}
	cout << endl;
}

int main() 
{

	test01();

	system("pause");

	return 0;
}
```



```c++
/**
set使用自定义数据类型和自定义排序规则
**/

#include <set>
#include <string>

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

class comparePerson
{
public:
	bool operator()(const Person& p1, const Person &p2)
	{
		//按照年龄进行排序  降序
		return p1.m_Age > p2.m_Age;
	}
};

void test01()
{
	set<Person, comparePerson> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



## Unordered_set

### Unordered_set 特点

-   unordered_set 容器，可直译为“无序 set 容器”。即 unordered_set 容器和 set 容器很像，唯一的区别就在于 set 容器会自行对存储的数据进行排序，而 unordered_set 容器不会。

-   不再以键值对的形式存储数据，而是直接存储数据的值 ；
-   容器内部存储的各个元素的值都互不相等，且不能被修改；
-   不会对内部存储的数据进行排序



### Unordered_set 构造

```c++
// 创建空的set
unordered_set<int> set1;

// 拷贝构造
unordered_set<int> set2(set1);

// 使用迭代器构造
unordered_set<int> set3(set1.begin(), set1.end());

// 使用数组作为其初值进行构造
unordered_set<int> set4(arr,arr+5);

// 移动构造
unordered_set<int> set5(move(set2));

// 使用处置列表进行构造
unordered_set<int> set6 {1,2,10,10};
```



### Unordered_set 判空, 查找, 计数, 清空

```c++
// 判断空
set1.empty();

// find()函数——查找
//查找2，找到返回迭代器，失败返回end()
set1.find(2);

// count()函数——出现次数
//返回指2出现的次数，0或1
set1.count(2);

// clear()函数——清空
set1.clear();
```



### Unordered_set insert()/emplace()相关

```c++
// insert()函数——插入元素
//插入元素，返回pair<unordered_set<int>::iterator, bool>
set1.insert(3);
//使用initializer_list插入元素
set1.insert({1,2,3});
//指定插入位置，如果位置正确会减少插入时间，返回指向插入元素的迭代器
set1.insert(set1.end(), 4);
//使用范围迭代器插入
set1.insert(set2.begin(), set2.end());

// insert() 传入单个元素
// 会返回一个 pair 对象
// 这个 pair 对象包含一个迭代器，以及一个附加的布尔值用来说明插入是否成功
// 如果元素被插入，返回的迭代器会指向新元素
// 如果没有被插入，迭代器指向阻止插入的元素
auto pr = words.insert("ninety"); // Returns a pair - an iterator & a bool value

// insert()传入两个参数（迭代器+待插入元素）
// 可以用一个迭代器作为insert()的第一个参数，它指定了元素被插入的位置
// 在这种情况下，只会返回一个迭代器
auto iter = words.insert (pr.first, "nine"); // 1st arg is a hint. Returns an iterator

// insert()传入初始化列表
// 插入初始化表中的元素
// 在这种情况下，什么都没有返回
words.insert({"ten", "seven", "six"});  // Inserting an initializer list

// emplace()函数——插入元素(转移构造)
// 使用转移构造函数添加新元素3，比insert效率高
set1.emplace(3);
```



### Unordered_set erase() 相关

```c++
// erase()函数——删除元素
// 删除操作，成功返回1，失败返回0
set1.erase(1);
// 删除操作，成功返回下一个pair的迭代器
set1.erase(set1.find(1));
// 删除set1的所有元素，返回指向end的迭代器
set1.erase(set1.begin(), set1.end());
```



### Unordered_set bucket 相关

```c++
// 返回容器中的篮子总数
set1.bucket_count();

// 返回1号篮子中的元素数
set1.bucket_size(1);

// 元素1在哪一个篮子
set1.bucket(1);

// 负载因子，返回每个篮子元素的平均数，即size/float(bucket_count);
set1.load_factor();

// 设置篮子的数量为20，并且重新rehash
set1.rehash(20);
```



## Pair

### Pair 特点

pair是将2个数据组合成一组数据，当需要这样的需求时就可以使用pair，如stl中的map就是将key和value放在一起来保存。另一个应用是，当一个函数需要返回2个数据的时候，可以选择pair。 pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量。



### Pair 构造与初始化

```c++
//创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
pair<T1, T2> p1;

//创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
pair<T1, T2> p1(v1, v2);

// 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
make_pair(v1, v2);

// pair的两个类型可以不一样
// 创建一个空对象anon，两个元素类型都是string
pair<string, string> anon;
// 创建一个空对象 word_count, 两个元素类型分别是string和int类型
pair<string, int> word_count;
// 创建一个空对象line，两个元素类型分别是string和vector类型
pair<string, vector<int> > line;

// 定义时进行成员初始化：
pair<string, string> author("James","Joy");。
pair<string, int> name_age("Tom", 18);
pair<string, int> name_age2(name_age);

// pair类型的使用相当的繁琐，如果定义多个相同的pair类型对象，可以使用typedef简化声明：
typedef pair<string,string> Author;
Author proust("March","Proust");
Author Joy("James","Joy");

// 变量间赋值
pair<int, double> p1(1, 1.2);
pair<int, double> p2 = p1;     
pair<int, double> p3；
p3 = p1;
```



### Pair 操作

```c++
// 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
p1 < p2;

// 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
p1 == p2;

// 返回对象p1中名为first的公有数据成员
p1.first;

// 返回对象p1中名为second的公有数据成员
p1.second;
```



### Pair 与 make_pair

```c++
pair<int, double> p1;
p1 = make_pair(1, 1.2);
```



### 通过tie获取pair元素值



```c++
/**
在某些清况函数会以pair对象作为返回值时，可以直接通过std::tie进行接收
**/

std::pair<std::string, int> getPreson() 
{
    return std::make_pair("Sven", 25);
}
 
int main(int argc, char **argv) 
{
    std::string name;
    int ages;
 
    std::tie(name, ages) = getPreson();
 
    std::cout << "name: " << name << ", ages: " << ages << std::endl;
 
    return 0;
}
```



Map/Multimap



Unordered_map



Hashmap



Hashset





STL 函数对象



STL 常用算法



