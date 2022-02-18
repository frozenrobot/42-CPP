#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target): Form("Presidential Pardon", 72, 45), _target(target)
{
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &toCopy): Form(toCopy), _target(toCopy._target)
{
    return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &toAssign)
{
	this->_target = toAssign._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const
{
    Form::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
