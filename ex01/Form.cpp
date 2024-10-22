
#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    this->isSigned = false;
}

Form::Form(const Form& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade Too High!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade Too Low!";
}



