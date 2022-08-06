#include <iostream>

struct Person
{
    int age;
    std::string name;
    int* ID;
};


int main()
{
    Person p1;
    p1.age = 18;
    p1.name = "wang";
    p1.ID = new int(100);

    Person p2 = p1;
    std::cout << p2.age << " " << p2.name << " " << *p2.ID << std::endl;

    p1.age = 19;
    p1.name = "li";
    std::cout << p1.age << " " << p1.name << " " << *p1.ID << std::endl;
    std::cout << p2.age << " " << p2.name << " " << *p2.ID << std::endl;

    delete p1.ID;
    delete p2.ID;   // 如果struct里面有指针, 那么在delete 的时候会删除两次

    return 0;
}