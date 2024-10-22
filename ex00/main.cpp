
#include "Bureaucrat.hpp"

#include <iostream>

int main() {

    Bureaucrat a("John", 1);
    std::cout << a << std::endl;

    try {
        Bureaucrat a("John", -1);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat a("John", 151);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat a("John", 1);
        a.incrementGrade(10);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat a("John", 150);
        a.decrementGrade(10);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}