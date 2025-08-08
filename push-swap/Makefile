# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 16:34:39 by smariapp          #+#    #+#              #
#    Updated: 2025/08/07 21:08:44 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = push_swap.c operations.c linkedlist.c kinda_like_libft.c input_validity.c\
		Libft/ft_atoi.c Libft/ft_split.c Libft/ft_isdigit.c \
		Libft/ft_strchr.c Libft/ft_strncmp.c 

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(OBJECTS)

re: fclean all

.PHONY: all bonus clean fclean re