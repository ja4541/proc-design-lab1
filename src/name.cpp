#include <iostream>
#include <string>

std::string getUserName() {
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    return name;
}