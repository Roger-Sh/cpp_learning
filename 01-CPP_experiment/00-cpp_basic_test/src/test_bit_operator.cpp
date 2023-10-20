#include <stdio.h>
#include <stdlib.h>

#include <iostream>

int main() {
    int a = 0;
    std::cout << "a: " << a << std::endl;
    a &= 1;
    std::cout << "a: " << a << std::endl;
    std::cout << "a & 1: " << (a & 1) << std::endl;

    a = 2;
    a &= 2;
    std::cout << "a: " << a << std::endl;
    std::cout << "a & 2: " << (a & 2) << std::endl;

    a = 4;
    a &= 4;
    std::cout << "a: " << a << std::endl;
    std::cout << "a & 4: " << (a & 4) << std::endl;

    return 0;
}