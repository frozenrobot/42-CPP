#include "Form.hpp"

Form::Form(std::string const name, int signgrade, int execgrade) : _name(name), _sign_grade(signgrade), _exec_grade(execgrade), _signed(false)
{
    if (this->_sign_grade < 1 || this->_exec_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->_sign_grade > 150 || this->_exec_grade > 150)
        throw Bureaucrat::GradeTooLowException(); 
}

Form::~Form(void)
{
    return;
}

Form::Form(Form const &toCopy) : _name(toCopy._name), _sign_grade(toCopy._sign_grade), _exec_grade(toCopy._exec_grade), _signed(toCopy._signed)
{
    if (this->_sign_grade < 1 || this->_exec_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->_sign_grade > 150 || this->_exec_grade > 150)
        throw Bureaucrat::GradeTooLowException();  
}

Form &Form::operator=(Form const &toAssign)
{
	this->_signed = toAssign._signed;
	return (*this);
}

std::string const Form::getName(void)
{
    return (this->_name);
}

int Form::getSignGrade(void) const
{
    return (this->_sign_grade);
}

int Form::getExecGrade(void) const
{
    return (this->_exec_grade);
}

void Form::beSigned(Bureaucrat &bcrat)
{
    if (bcrat.getGrade() > this->_sign_grade)
        throw Form::GradeTooLowException();
    else if (this->_signed)
        throw Form::AlreadySignedException();
    else
        this->_signed = true;
}

bool Form::isSigned(void)
{
    if (this->_signed)
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &o, Form &instance)
{
	o << "Form name: " << instance.getName() << ", Form signed: " << ((instance.isSigned()) ? "Yes" : "No") << ", Sign Grade: " << instance.getSignGrade() << ", Execute Grade: " << instance.getExecGrade();
	return (o);
}


Form::GradeTooHighException::GradeTooHighException() throw()
{
    return;
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &toCopy) throw()
{
    return;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
    return;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const GradeTooHighException &toAssign) throw() 
{
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "EXCEPTION: Grade too high!";
}


Form::GradeTooLowException::GradeTooLowException() throw()
{
    return;
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &toCopy) throw()
{
    return;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
    return;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException &toAssign) throw() 
{
	return (*this);
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "EXCEPTION: Grade too low!";
}



Form::AlreadySignedException::AlreadySignedException() throw()
{
    return;
}

Form::AlreadySignedException::AlreadySignedException(const AlreadySignedException &toCopy) throw()
{
    return;
}

Form::AlreadySignedException::~AlreadySignedException() throw()
{
    return;
}

Form::AlreadySignedException &Form::AlreadySignedException::operator=(const AlreadySignedException &toAssign) throw() 
{
	return (*this);
}

const char *Form::AlreadySignedException::what() const throw()
{
    return "EXCEPTION: Form already signed.";
}
