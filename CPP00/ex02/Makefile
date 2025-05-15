# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 15:56:14 by vvasiuko          #+#    #+#              #
#    Updated: 2025/03/31 15:57:17 by vvasiuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tjoyd
CPPFLAGS = -Wextra -Wall -Werror -std=c++98
SRCS = tests.cpp Account.cpp
OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)
	
clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re