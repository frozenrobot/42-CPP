#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &instance);

#endif