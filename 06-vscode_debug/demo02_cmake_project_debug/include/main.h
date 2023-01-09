#ifndef VSCODE_CMAKE_DEBUG_DEMO
#define VSCODE_CMAKE_DEBUG_DEMO

#include <iostream>
#include <string>

/**
 * @brief a class of Person, store name, age, telephone number
 * 
 */
class Person {
public:
    Person();
    Person(const std::string &name, const int &age, const std::string &tel_num);

    void SetName(const std::string &name);
    void SetAge(const int &age);
    void SetTelNum(const std::string &tel_num);
    void ShowPersonInfo();

private:
    std::string name_;
    int age_;
    std::string tel_num_;
};

#endif  // VSCODE_CMAKE_DEBUG_DEMO