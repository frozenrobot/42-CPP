#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        // class FormMatch
        // {
        //     private:
        //         std::string name;
        //         std::string target;
        //     public:
        //         FormMatch(std::string name, std::string target);
        //         Form *execute(std::string type)
        // };
        std::string name;
        std::string target;
        std::string matches[3];
    public:
        Intern();
        Intern(Intern const &toCopy);
        Intern &operator=(Intern const &toAssign);
        virtual ~Intern();
        Form *makeForm(std::string const &formName, std::string const &target) const;

        class NonExistentFormException: public std::exception {
            virtual const char* what() const throw()
            {
                return "EXCEPTION: Form does not exist, check syntax.";
            }
        };
};

#endif