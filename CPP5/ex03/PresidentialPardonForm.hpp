#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
class PresidentialPardonForm;
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(std::string const target);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const &toCopy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &toAssign);

        void execute(Bureaucrat &executor) const;
};

#endif