#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bureaucrat("John", 1);
        Form form("Form1", 1, 1);
        bureaucrat.signForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bureaucrat("Jane", 150);
        Form form("Form2", 1, 1);
        bureaucrat.signForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bureaucrat("Jane", 1);
        Form form("Form3", 1, 1);
        bureaucrat.signForm(form);
        bureaucrat.signForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
