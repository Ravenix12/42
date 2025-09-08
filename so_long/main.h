/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:54:26 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 22:09:22 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include </usr/include/X11/X.h>
# include </usr/include/X11/keysymdef.h>

# define ESC 0xff1b
# define UP 0xff52
# define DOWN 0xff54
# define LEFT 0xff51
# define RIGHT 0xff53

typedef struct s_player
{
	int	exit;
	int	player;
	int	collectibles;
	int	collected;
	int	enemy;
	int	exit_m;
	int	lines;
	int	length;
	int	movements;
	int	dy;
	int	dx;
}	t_p;

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_display
{
	void	**player;
	void	*collectible;
	void	**wall;
	void	*emp;
	void	**exit;
	void	**enemy;
}	t_dis;

typedef struct params
{
	t_data	*data;
	t_p		*info;
	t_dis	*display;
	char	**map;
}	t_par;

//validity
int		check_walls(char *line, int length);
t_p		*check_invalid(int fd);
int		check_epc(t_p *info, char *line, int final);
void	error_exit(char *error, int fd, char *line, t_p *info);
//utilities
int		nl(char *str);
void	free_arr(char **arr);
void	counter(int num);
void	put_counter(t_par *params);
//map_config
char	**save_map(int fd, t_p *info);
void	free_player(char **arr, t_p *info);
void	malloc_exit(char **arr, t_p *info);
int		*find_coordinates(char **map, char c, t_p *info);
char	**duplicate_map(char **map, t_p *info);
//solvable;
char	**solvable_entry(int fd, t_p *info);
void	check_solvable(char **dup, char **map, t_p *info, int fd);
void	unsolvable_exit(char **map, char **dup, int *coor, t_p *info);
int	exit_reachable(char **map, int *E);
//floodfill
void	fill_vertical(char **map, int *coor, t_p *info);
void	fill_horizontal(char **map, int *coor, t_p *info);
void	assign(char **map, int *coor, char c, t_p *info);
//lib
int		ft_close(t_par *params);
int		handle_inputs(t_par *params);
void	lib_entry(char **map, t_p *info);
t_par	*set_param(char **map, t_p *info, t_data *data, t_dis *dis);
void	config_display(t_p *info, t_data *data);
//init_pics
void	init_pics(t_dis	*image, char **map, t_p *info, t_data *data);
int		set_image(void **location, char *path, t_data *data, int flag);
void	free_display(t_data *data, t_dis *images);
void	malloc_fail(char **map, t_p *info, t_data *data, t_dis *images);
void	free_imgarr(void **arr, t_data *data);
//input_handling
void	is_enemy(t_par *params, int d, int *p_coor);
int		is_movable(t_par *params, int dir, int *c);
void	check_end(t_par *params, int *p_coor);
int		modify_map(int	*c, t_par *params, int dir, char pdir);
int		ft_keypress(int keycode, t_par *params);
//display
void	display_cf(int i, int x, t_par *params, int shift);
void	display_ncf(int i, int j, t_par *params, int *tl);
int		display_screen(t_par *params);
int		*find_top_left(t_par *params);

#endif