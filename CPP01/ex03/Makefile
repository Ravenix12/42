# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/25 11:33:39 by smariapp          #+#    #+#              #
#    Updated: 2026/06/25 12:11:50 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Unnecessary_violence
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
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
