#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): Form("Shrubbery Creation", 145, 137), _target(target)
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &toCopy): Form(toCopy), _target(toCopy._target)
{
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &toAssign)
{
	this->_target = toAssign._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
    Form::execute(executor);
    std::string filename = (this->_target + "_shrubbery");
	std::ofstream outfile(filename);
    outfile <<  "               ,@@@@@@@,\n\
        ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
        ,&%%&%&&%,@@@@@/@@@@@@,8888\\8/8o\n\
    ,%&\\&&%&&%,@@@\\@@/@@@88\\8888/88'\n\
    %&&%&%&/%&&%@@\\@/ /@@@88888\\8888'\n\
    %&&%/ %&%%&&@\\ V /@@' `88\\ `/88'\n\
    `&%\\` /%&'    |.|        \\'|8'\n\
        |o|        | |         | |\n\
        |.|        | |         | |\n\
        \\/ ._\\/_/__/  ,\\//__\\/.  \\//__/_\n";
	outfile.close();
}
