# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 12:13:57 by smariapp          #+#    #+#              #
#    Updated: 2025/12/30 22:21:11 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BNAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER  = main.h

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = main.c utilities.c

BSOURCES = bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c

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
	rm -f $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

it: all clean

.PHONY: all bonus clean fclean re it


