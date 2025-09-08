# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/22 18:10:06 by smariapp          #+#    #+#              #
#    Updated: 2025/09/08 20:04:13 by smariapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./Libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = ./minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

SOURCES = main.c validity.c utilities.c solvable.c map_config.c floodfill.c lib.c input_handling.c init_pics.c display.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
	
BSOURCES = main.c validity_bonus.c utilities.c solvable.c map_config.c floodfill_bonus.c lib.c input_handling.c init_pics_bonus.c display_bonus.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -L/usr/lib/X11 -lm -o $(NAME)
	
bonus: $(BNAME)
$(BNAME): $(BOBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BOBJECTS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -L/usr/lib/X11 -lm -o $(BNAME)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(BNAME) $(OBJECTS) $(BOBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all bonus clean fclean re
