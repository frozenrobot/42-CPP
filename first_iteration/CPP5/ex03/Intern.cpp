#include "Intern.hpp"

Intern::Intern(void)
{
    this->matches[0] = "shrubbery creation";
	this->matches[1] = "robotomy request";
	this->matches[2] = "presidential pardon";
}

Intern::Intern(Intern const &toCopy)
{
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern &Intern::operator=(Intern const &toAssign)
{
	return (*this);
}

Form *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	Form *form = nullptr;
    int i = 0;
	while (i < 3)
    {
        if (this->matches[i] == formName)
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        case 3:
            throw Intern::NonExistentFormException();
            return nullptr;
    }
	std::cout << "Intern creates " << matches[i] << std::endl;
	return (form);
}