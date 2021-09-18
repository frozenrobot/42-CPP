#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat(std::string const name, int grade);
        ~Bureaucrat(void);
        Bureaucrat(Bureaucrat const &toCopy);
        Bureaucrat &operator=(Bureaucrat const &toAssign);

        std::string const getName(void);
        int getGrade(void) const;
        void increaseGrade(void);
        void decreaseGrade(void);
        void signForm(Form &form);
        void executeForm(Form const & form);

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
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &instance);

#endif