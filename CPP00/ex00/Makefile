# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 16:46:51 by vvasiuko          #+#    #+#              #
#    Updated: 2025/03/23 16:47:32 by vvasiuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CPPFLAGS = -Wextra -Wall -Werror -std=c++17
SRCS = megaphone.cpp
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