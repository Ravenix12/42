# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/08 18:05:21 by smariapp          #+#    #+#              #
#    Updated: 2026/09/22 21:32:59 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INC = Intern.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp AForm.hpp
SRC = Intern.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp AForm.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME) garden_shrubbery.txt polyGarden_shrubbery.txt

re: fclean all

it: re clean

.PHONY: all clean fclean re it