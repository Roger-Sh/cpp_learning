# CPP_STL_Note



## 1 STL 基本概念

- STL - Standard Template Library
- STL 分为
  - 容器，container
    - 序列式容器
      - 强调排序， 每个元素有固定位置
    - 关联式容器
      - 强调关系， 没有严格的顺序
    - 常用数据结构
      - vector
      - list
      - tree
      - stack
      - deque
      - set
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



## 2 String

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







## 3 Vector

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



## 4 Deque

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



5 Stack



6 Queue



7 List



8 Set/Multiset



9 Map/Multimap



10 STL 函数对象



11 STL 常用算法



