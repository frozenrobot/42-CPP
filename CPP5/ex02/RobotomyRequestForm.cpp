#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target): Form("Robotomy Request", 72, 45), _target(target)
{
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &toCopy): Form(toCopy), _target(toCopy._target)
{
    return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &toAssign)
{
	this->_target = toAssign._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const
{
	srand(time(NULL));
    Form::execute(executor);
	std::cout << " < ZZDZ DDDZD DZDDZ DD > " << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << ": robotomy failed" << std::endl;
}
