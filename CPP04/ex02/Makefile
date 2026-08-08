# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 15:37:26 by smariapp          #+#    #+#              #
#    Updated: 2026/08/01 17:48:53 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INC = Animal.hpp Cat.hpp Dog.hpp Brain.hpp
SRC = Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp
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
