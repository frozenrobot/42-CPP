NAME = replace
SRCS = main.cpp
FLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *.replace

fclean: clean
	rm -f $(NAME)

re: fclean all