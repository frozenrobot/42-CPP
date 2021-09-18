#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
class ShrubberyCreationForm;
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(std::string const target);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(ShrubberyCreationForm const &toCopy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &toAssign);

        void execute(Bureaucrat &executor) const;

        class OpenException: public std::exception {
            virtual const char* what() const throw()
            {
                return "EXCEPTION: Cannot open file";
            }
        };
        class WriteException: public std::exception {
            virtual const char* what() const throw()
            {
                return "EXCEPTION: Cannot write to file";
            }
        };
};

#endif