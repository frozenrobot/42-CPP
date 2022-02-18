#ifndef FORM_HPP
#define FORM_HPP
class Form;
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
    
    public:
        Form(std::string const name, int signgrade, int execgrade);
        ~Form(void);
        Form(Form const &toCopy);
        Form &operator=(Form const &toAssign);

        std::string const getName(void);
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        bool isSigned(void);
        void beSigned(Bureaucrat &bcrat);

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
};

std::ostream &operator<<(std::ostream &o, Form &instance);

#endif