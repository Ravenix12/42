# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shivani <shivani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 19:59:56 by smariapp          #+#    #+#              #
#    Updated: 2026/02/25 10:19:08 by shivani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -lpthread
HEADER  = main.h

SOURCES = main.c validation.c init.c process.c utilities.c ft_putnbr_fd.c
OBJECTS = $(SOURCES:.c=.o)

all = $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean:
	rm -f $(NAME) $(OBJECTS)
re:
	clean all
it: 
	all clean

.PHONY: all clean fclean it
