NAME = form
SRCS = main.cpp Bureaucrat.cpp Form.cpp
FLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all