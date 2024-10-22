#include "ShrubberryCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
ShrubberryCreationForm::ShrubberryCreationForm(const std::string& target) : AForm("ShrubberryCreationForm", 145, 137), target(target) {}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm& other) : AForm(other), target(other.target) {}

ShrubberryCreationForm& ShrubberryCreationForm::operator=(const ShrubberryCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberryCreationForm::~ShrubberryCreationForm() {}

void ShrubberryCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream file(target + "_shrubbery");
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open file");
    }
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    file.close();
}
