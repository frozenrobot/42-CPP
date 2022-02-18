#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        std::string name;
        std::string target;
        std::string matches[3];
    public:
        Intern();
        Intern(Intern const &toCopy);
        Intern &operator=(Intern const &toAssign);
        virtual ~Intern();
        Form *makeForm(std::string const &formName, std::string const &target) const;

        class NonExistentFormException : public std::exception
		{
			public:
				NonExistentFormException () throw();
				NonExistentFormException (const NonExistentFormException &toCopy) throw();
				NonExistentFormException &operator= (const NonExistentFormException &toAssign) throw();
				virtual ~NonExistentFormException() throw();
				const char *what() const throw();
		};

};

#endif