# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 17:17:37 by smariapp          #+#    #+#              #
#    Updated: 2026/03/17 19:12:35 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Contact.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

it: re clean

.PHONY: all clean fclean re it