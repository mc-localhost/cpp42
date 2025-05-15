CPP     := c++
CPPFLAGS:= -Wall -Wextra -Werror -std=c++11

NAME    := animals
SRCS    := main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS    := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
