#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    this->isSigned = false;
}

AForm::AForm(const AForm& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.getIsSigned();
    }
    return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade Too High!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade Too Low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form Not Signed!(cannot execute)";
}

const char* AForm::FormAlreadySignedException::what() const throw() {
    return "Form Already Signed!(cannot sign)";
}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (this->isSigned) {
        throw FormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}
