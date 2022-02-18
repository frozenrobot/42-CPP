#ifndef FORM_HPP
#define FORM_HPP

class Form;
#include "Bureaucrat.hpp"

class Form
{
    protected:
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
    
    public:
        Form(std::string const name, int signgrade, int execgrade);
        virtual ~Form(void);
        Form(Form const &toCopy);
        Form &operator=(Form const &toAssign);

        std::string const getName(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        bool isSigned(void) const;
        void beSigned(Bureaucrat &bcrat);
        virtual void execute(Bureaucrat &bureaucrat) const = 0;

        class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException () throw();
				GradeTooHighException (const GradeTooHighException &toCopy) throw();
				GradeTooHighException &operator= (const GradeTooHighException &toAssign) throw();
				virtual ~GradeTooHighException() throw();
				const char *what() const throw();
		};

        class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException () throw();
				GradeTooLowException (const GradeTooLowException &toCopy) throw();
				GradeTooLowException &operator= (const GradeTooLowException &toAssign) throw();
				virtual ~GradeTooLowException() throw();
				const char *what() const throw();
		};

        class AlreadySignedException : public std::exception
		{
			public:
				AlreadySignedException () throw();
				AlreadySignedException (const AlreadySignedException &toCopy) throw();
				AlreadySignedException &operator= (const AlreadySignedException &toAssign) throw();
				virtual ~AlreadySignedException() throw();
				const char *what() const throw();
		};

        class UnsignedFormException : public std::exception
		{
			public:
				UnsignedFormException () throw();
				UnsignedFormException (const UnsignedFormException &toCopy) throw();
				UnsignedFormException &operator= (const UnsignedFormException &toAssign) throw();
				virtual ~UnsignedFormException() throw();
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form &instance);

#endif