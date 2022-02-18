#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
class RobotomyRequestForm;
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(std::string const target);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const &toCopy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &toAssign);

        void execute(Bureaucrat &executor) const;
};

#endif