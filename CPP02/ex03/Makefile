# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shivani <shivani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 20:46:18 by smariapp          #+#    #+#              #
#    Updated: 2026/07/10 18:49:17 by shivani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Fixed.cpp Point.cpp Bsp.cpp main.cpp
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