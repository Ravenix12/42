# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shivani <shivani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 19:59:56 by smariapp          #+#    #+#              #
#    Updated: 2026/03/03 11:51:50 by shivani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFLAGS = -lpthread
HEADER  = philo.h

SOURCES = main.c validation.c init.c process.c monitor.c ft_putnbr_fd.c utilities.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all
it: re clean

.PHONY: all clean fclean re it
