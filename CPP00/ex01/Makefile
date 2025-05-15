# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 16:46:51 by vvasiuko          #+#    #+#              #
#    Updated: 2025/03/24 15:19:04 by vvasiuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CPPFLAGS = -Wextra -Wall -Werror -std=c++17
# HEADERS = Contact.hpp PhoneBook.hpp
SRCS = main.cpp PhoneBook.cpp Contact.cpp
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