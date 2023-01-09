#include <iostream>

int main() {
    std::cout << "please enter a string" << std::endl;
    std::string str;
    while (std::getline(std::cin, str)) {
        if (str[0] == 'q') {
            std::cout << "quit" << std::endl;
            break;
        } else {
            std::cout << str << std::endl;
        }
    }

    return 0;
}