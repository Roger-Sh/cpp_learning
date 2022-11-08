#include <iostream>

class A
{
public:
    A(std::string name) : name_(name)
    {

    }

    std::string name_;

    void show_name()
    {
        std::cout << name_ << std::endl;
    }    
};

class B
{
public:
    B(std::string name) : 
        name_(name),
        a1_(name)
    {
        a2_ = new A(name);
    }

    std::string name_;
    A a1_;
    A* a2_;

};


int main()
{
    std::string a_class_name = "a_class";
    A a_class(a_class_name);

    std::cout << "a_class.name_: " << a_class.name_ << std::endl;


    std::string b_class_name = "b_class";
    B b_class(b_class_name);

    std::cout << "b_class.name_ : " << b_class.name_ << std::endl;
    std::cout << "b_class.a1_.name_: " << b_class.a1_.name_ << std::endl;
    std::cout << "b_class.a2_->name_: " << b_class.a2_->name_ << std::endl;

    b_class.a1_.show_name();
    b_class.a2_->show_name();


}