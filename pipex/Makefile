# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 12:13:57 by smariapp          #+#    #+#              #
#    Updated: 2025/08/02 15:46:56 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = main.c utilities.c Libft/ft_split.c Libft/ft_strlen.c Libft/ft_strlcpy.c Libft/ft_strchr.c \
		Libft/ft_strdup.c Libft/ft_strjoin.c

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
