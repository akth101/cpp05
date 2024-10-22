
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    //ShrubberryCreationForm test
    {
        //normal operation
        std::cout << "[normal operation] - ShrubberryCreationForm" << std::endl;
        Bureaucrat bureaucrat("John", 1);
        ShrubberryCreationForm form("home1");
        bureaucrat.signForm(form);    
        bureaucrat.executeForm(form);
        std::cout << std::endl;
    }
    //RobotomyRequestForm test
    {
        //normal operation
        std::cout << "[normal operation] - RobotomyRequestForm" << std::endl;
        Bureaucrat bureaucrat("John", 1);
        RobotomyRequestForm form("home6");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
        std::cout << std::endl;
    }

    //PresidentialPardonForm test
    {
        //normal operation
        std::cout << "[normal operation] - PresidentialPardonForm" << std::endl;
        Bureaucrat bureaucrat("John", 1);
        PresidentialPardonForm form("home7");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
        std::cout << std::endl;
    }
    {
        //already signed, but try to sign again
        std::cout << "[already signed, but try to sign again]" << std::endl;
        Bureaucrat bureaucrat("John", 1);
        ShrubberryCreationForm form("home2");
        bureaucrat.signForm(form);
        bureaucrat.signForm(form);
        std::cout << std::endl;
    }
    {
        //not signed, but try to execute
        std::cout << "[not signed, but try to execute]" << std::endl;
        Bureaucrat bureaucrat("John", 1);
        ShrubberryCreationForm form("home3");
        bureaucrat.executeForm(form);
        std::cout << std::endl;
    }
    {
        //grade too low, try to execute
        std::cout << "[grade too low, try to execute]" << std::endl;
        Bureaucrat bureaucrat1("John", 1);
        Bureaucrat bureaucrat2("Jane", 150);
        ShrubberryCreationForm form("home4");
        bureaucrat1.signForm(form);
        bureaucrat2.executeForm(form);
        std::cout << std::endl;
    }
    {
        //grade too low, but try to sign
        std::cout << "[grade too low, but try to sign]" << std::endl;
        Bureaucrat bureaucrat("John", 150);
        ShrubberryCreationForm form("home5");
        bureaucrat.signForm(form);
        std::cout << std::endl;
    }
    return 0;
}

