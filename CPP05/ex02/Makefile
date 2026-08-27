# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/08 18:05:21 by smariapp          #+#    #+#              #
#    Updated: 2026/08/19 22:12:17 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INC = Bureaucrat.hpp Form.hpp
SRC = Bureaucrat.cpp Form.cpp main.cpp
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