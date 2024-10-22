#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade(int value);
        void decrementGrade(int value);
        void signForm(AForm& form);
        void executeForm(AForm& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
