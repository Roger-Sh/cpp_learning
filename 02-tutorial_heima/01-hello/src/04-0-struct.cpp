#include <iostream>

using namespace std;

// 结构体
struct student
{
    // member
    string name;
    int age;
    int score;
}stu3;      // 结构体创建变量方式3 直接写在结构体下面


// 结构体嵌套
struct teacher
{
    //member
    int id;
    string name;
    int age;
    struct student stu;     //子结构体 学生
};


// 结构体传参，值传递，函数内参数变化不影响外部变量
void print_student_1(struct student stu)
{
    stu.age = 28;
    cout << "Name in func: " << stu.name << endl;
    cout << "Age in func: " << stu.age << endl;
    cout << "Score in func: " << stu.score << endl;
}

// 结构体传参，地址传递，函数内参数变化会同时改变外部参数
void print_student_2(struct student *stu)
{
    stu->age = 28;
    cout << "Name in func: " << stu->name << endl;
    cout << "Age in func: " << stu->age << endl;
    cout << "Score in func: " << stu->score << endl;
}

// 结构体传参，地址传递，使用const防止变量发生变化
void print_student_3(const struct student *stu)
{
    // stu->age = 28;   // 因为const，无法改变参数
    cout << "Name in func: " << stu->name << endl;
    cout << "Age in func: " << stu->age << endl;
    cout << "Score in func: " << stu->score << endl;
}



int main()
{
    //总结1：定义结构体时的关键字是struct，不可省略
    //总结2：创建结构体变量时，关键字struct可以省略
    //总结3：结构体变量利用操作符 ''.''  访问成员

    // 结构体变量创建方式1
    struct student stu1;    // struct 可以省略
    stu1.name = "Zhang san";
    stu1.age = 18;
    stu1.score = 100;
    cout << "Name: " << stu1.name << endl;
    cout << "Age: " << stu1.age << endl;
    cout << "Score: " << stu1.score << endl;


    // 结构体创建变量方式2
    struct student stu2 = {"Li si", 19, 60};
    cout << "Name: " << stu2.name << endl;
    cout << "Age: " << stu2.age << endl;
    cout << "Score: " << stu2.score << endl;

 
    // 结构体创建变量方式3
    stu3.name = "Wang wu";
    stu3.age = 19;
    stu3.score = 90;
    cout << "Name: " << stu2.name << endl;
    cout << "Age: " << stu2.age << endl;
    cout << "Score: " << stu2.score << endl;


    // 结构体数组
    struct student stu_arr[3]=
    {
        {"Zhang san", 18, 100},
        {"Li si", 19, 60},
        {"Wang wu", 18, 90}
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "Name: " << stu_arr[i].name << endl;
        cout << "Age: " << stu_arr[i].age << endl;
        cout << "Score: " << stu_arr[i].score << endl;
    }


    // 结构体指针
    struct student * p = &stu1;     // 定义结构体指针
    p->score = 80;                  // 通过->访问指针指向的结构体成员
    cout << "Name: " << p->name << endl;
    cout << "Age: " << p->age << endl;
    cout << "Score: " << p->score << endl;


    // 结构体嵌套
    struct teacher t1;
    t1.id = 100;
    t1.name = "Wang";
    t1.age = 40;
    t1.stu.name = "Zhang";
    t1.stu.age = 18;
    t1.stu.score = 100;


    // 结构体传参，值传递，函数内结构体的内容变化不影响外部原变量
    print_student_1(stu1);
    cout << "Name in main: " << stu1.name << endl;
    cout << "Age in main: " << stu1.age << endl;
    cout << "Score in main: " << stu1.score << endl;
    
    // 结构体传参，地址传递，函数内结构体内容变化会同时改变原变量
    print_student_2(&stu2);
    cout << "Name in main: " << stu1.name << endl;
    cout << "Age in main: " << stu1.age << endl;
    cout << "Score in main: " << stu1.score << endl;

    // 结构体传参，地址传递，使用const防止参数变化
    print_student_3(&stu3);
    cout << "Name in main: " << stu1.name << endl;
    cout << "Age in main: " << stu1.age << endl;

    return 0;    

}