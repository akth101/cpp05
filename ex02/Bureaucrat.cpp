#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade(int value) {
    if (this->grade - value < 1)
        throw GradeTooHighException();
    this->grade -= value;
}

void Bureaucrat::decrementGrade(int value) {
    if (this->grade + value > 150)
        throw GradeTooLowException();
    this->grade += value;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade Too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << *this << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << *this << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm& form) {
    try {
        form.execute(*this);
        std::cout << *this << " executed successfully " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << *this << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
