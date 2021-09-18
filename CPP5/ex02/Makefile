NAME = forms
SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
FLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all