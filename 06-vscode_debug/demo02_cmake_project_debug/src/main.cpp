#include "main.h"

#include <iostream>

Person::Person() {
    this->name_ = "prefix_name";
    this->age_ = 0;
    this->tel_num_ = "00000000000";
}

Person::Person(const std::string &name, const int &age, const std::string &tel_num) {
    this->name_ = name;
    this->age_ = age;
    this->tel_num_ = tel_num;
}

void Person::SetName(const std::string &name) {
    this->name_ = name;
}

void Person::SetAge(const int &age) {
    this->age_ = age;
}

void Person::SetTelNum(const std::string &tel_num) {
    this->tel_num_ = tel_num;
}

void Person::ShowPersonInfo() {
    std::cout <<"===================================" << std::endl;
    std::cout << "name: " << this->name_ << std::endl;
    std::cout << "age: " << this->age_ << std::endl;
    std::cout << "tel: " << this->tel_num_ << std::endl;
}

inline bool Quit() {
    std::string str;
    std::cout << "enter q to quit, others to continue." << std::endl;
    std::getline(std::cin, str);

    if (str[0] == 'q') {
        std::cout << "quit" << std::endl;
        return true;
    } else {
        std::cout << str << std::endl;
        return false;
    }
}

int main() {
    Person p1("xiaoming", 10, "13345678901");
    p1.ShowPersonInfo();

    Person p2;
    p2.ShowPersonInfo();

    p2.SetName("xiaowang");
    p2.SetAge(12);
    p2.SetTelNum("12345675678");
    p2.ShowPersonInfo();

    int age = 12;
    while (true) {
        if(Quit())
        {
            break;
        }

        age++;
        p2.SetAge(age);
        p2.ShowPersonInfo();
    }

    return 0;
}