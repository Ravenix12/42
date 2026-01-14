# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shivani <shivani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 12:13:57 by smariapp          #+#    #+#              #
#    Updated: 2026/01/14 15:02:48 by shivani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BNAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER  = main.h

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = main.c utilities.c mandatory.c

BSOURCES = bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c bonus_utils.c mandatory.c utilities.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

bonus: $(BNAME)

$(BNAME): $(BOBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJECTS) -L$(LIBFT_DIR) -lft -o $(BNAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BNAME) $(OBJECTS) $(BOBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

it: all clean

bbb: bonus clean

.PHONY: all bonus clean fclean re it bbb