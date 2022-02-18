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
            const char * what() const throw()
            {
                return "EXCEPTION: Grade too high!";
            }
        };

        class GradeTooLowException : public std::exception
        {
            const char * what() const throw()
            {
                return "EXCEPTION: Grade too low!";
            }
        };

        class AlreadySignedException : public std::exception
        {
            const char * what() const throw()
            {
                return "EXCEPTION: Form already signed.";
            }
        };

        class UnsignedFormException: public std::exception 
        {
	        const char* what() const throw()
            {
                return "EXCEPTION: Form not signed.";
            }
	    };
};

std::ostream &operator<<(std::ostream &o, Form &instance);

#endif