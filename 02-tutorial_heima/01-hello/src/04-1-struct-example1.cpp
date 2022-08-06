#include <iostream>
#include <ctime>

using namespace std;

/*
学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
最终打印出老师数据以及老师所带的学生数据。
*/

struct student
{
    string name;
    int score;
};

struct teacher
{
    string name;
    struct student stu_array[5];
};



// generate data for teacher array and its student array
void allocateSpace(teacher teacher_array[], int len)
{
    string tName = "教师";
    string sName = "学生";
    string nameSeed = "ABCDE";

    for (int i = 0; i < len; i++)
    {
        teacher_array[i].name = tName + nameSeed[i];

        for (int j = 0; j < 5; j++)
        {
            teacher_array[i].stu_array[j].name = sName + nameSeed[j];
            teacher_array[i].stu_array[j].score = rand() % 61 + 40;
        }        
    }
}


// print teacher array and student array
void printTeachers(struct teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "Teacher name: " << tArray[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "Student name: " << tArray[i].stu_array[j].name << " score: " << tArray[i].stu_array[j].score << endl;
        }
    }
}


int main()
{
    srand((unsigned int)time(NULL));    // random seed #include <ctime>

    struct teacher teacher_array[3];    

    int len_teacher_array = sizeof(teacher_array) / sizeof(teacher);

    allocateSpace(teacher_array, len_teacher_array);    // generate data 
    printTeachers(teacher_array, len_teacher_array);    // print teacher array and its stu array    

    return 0;
}