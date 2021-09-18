#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();    
}

Bureaucrat::~Bureaucrat(void)
{
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &toCopy) : _name(toCopy._name), _grade(toCopy._grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();  
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &toAssign)
{
	this->_grade = toAssign._grade;
	return (*this);
}

std::string const Bureaucrat::getName(void)
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::increaseGrade(void)
{
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
    if (form.isSigned())
		std::cout << "Bureaucrat " << this->_name << " cannot sign form " << form.getName()	<< " because the form is already signed." << std::endl;
	else if (form.getSignGrade() < this->_grade)
		std::cout << "Bureaucrat " << this->_name << " cannot sign form " << form.getName()	<< " because grade too low." << std::endl;
	else
		std::cout << "Bureaucrat " << this->_name << " signs " << form.getName() << std::endl;
	form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &instance)
{
	o << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return (o);
}