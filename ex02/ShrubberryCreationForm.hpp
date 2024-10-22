
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberryCreationForm : public AForm {
    private:
        std::string target;

    public:
        ShrubberryCreationForm(const std::string& target);
        ShrubberryCreationForm(const ShrubberryCreationForm& other);
        ShrubberryCreationForm& operator=(const ShrubberryCreationForm& other);
        ~ShrubberryCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif