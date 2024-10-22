#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Drilling....." << std::endl;
    std::time_t currentTime = std::time(nullptr);
    (currentTime % 2 == 0)
        ? std::cout << this->target << " has been robotomized successful." << std::endl
        : std::cout << this->target << " has failed to robotomize." << std::endl;
}
