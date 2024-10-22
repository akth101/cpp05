#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormAlreadySignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

#endif