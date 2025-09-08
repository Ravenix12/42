/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:07:21 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 20:53:46 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	is_enemy(t_par *params, int d, int *p_coor)
{
	int		x;
	int		y;
	int		ret;

	y = p_coor[0];
	x = p_coor[1];
	ret = 0;
	if (d == UP && params->map[y - 1][x] == 'X')
		ret = 1;
	else if (d == DOWN && params->map[y + 1][x] == 'X')
		ret = 1;
	else if (d == LEFT && params->map[y][x - 1] == 'X')
		ret = 1;
	else if (d == RIGHT && params->map[y][x + 1] == 'X')
		ret = 1;
	if (ret == 1)
	{
		free(p_coor);
		write(1, "\n", 1);
		write(1, "You were supposed to help me find the treasure, not", 51);
		write(1, " feed me to the Octopus ....\n", 29);
		write(1, "\n", 1);
		ft_close(params);
	}
}

void	check_end(t_par *params, int *p_coor)
{
	char	**map;
	int		*coor;

	map = params->map;
	free(p_coor);
	if (params->info->exit_m)
	{
		coor = find_coordinates(map, 'O', params->info);
		if (coor != NULL)
			return (free(coor));
		write(1, "\n", 1);
		write(1, "Thanks for helping me find the treasure!\n", 41);
		write(1, "\n", 1);
		ft_close(params);
	}
	return ;
}

int	modify_map(int	*c, t_par *params, int dir, char pdir)
{
	char	to;

	if (dir == UP)
		to = params->map[c[0] - 1][c[1]];
	if (dir == DOWN)
		to = params->map[c[0] + 1][c[1]];
	if (dir == LEFT)
		to = params->map[c[0]][c[1] - 1];
	if (dir == RIGHT)
		to = params->map[c[0]][c[1] + 1];
	params->map[c[0]][c[1]] = '0';
	if (dir == UP)
		params->map[c[0] - 1][c[1]] = pdir;
	if (dir == DOWN)
		params->map[c[0] + 1][c[1]] = pdir;
	if (dir == LEFT)
		params->map[c[0]][c[1] - 1] = 'L';
	if (dir == RIGHT)
		params->map[c[0]][c[1] + 1] = 'P';
	if (to == 'C')
		params->info->collected += 1;
	counter(params->info->movements);
	if (params->info->collected == params->info->collectibles)
		return (100);
	return (1);
}

int	is_movable(t_par *params, int d, int *c)
{
	char	**map;
	int		x;
	int		y;
	int		ret;

	y = c[0];
	x = c[1];
	map = params->map;
	ret = 0;
	if (d == UP && map[y - 1][x] != 'E' && map[y - 1][x] != '1')
		ret = 1;
	else if (d == DOWN && map[y + 1][x] != 'E' && map[y + 1][x] != '1')
		ret = 1;
	else if (d == LEFT && map[y][x - 1] != 'E' && map[y][x - 1] != '1')
		ret = 1;
	else if (d == RIGHT && map[y][x + 1] != 'E' && map[y][x + 1] != '1')
		ret = 1;
	if (ret == 1)
		params->info->movements += 1;
	return (is_enemy(params, d, c), ret);
}

int	ft_keypress(int keycode, t_par *params)
{
	int		*p_coor;
	char	p;
	int		exit_cond;
	int		*e_coor;

	exit_cond = 0;
	if (keycode == ESC)
		ft_close(params);
	p_coor = find_coordinates(params->map, 'P', params->info);
	if (p_coor == NULL)
		p_coor = find_coordinates(params->map, 'L', params->info);
	p = params->map[p_coor[0]][p_coor[1]];
	if (is_movable(params, keycode, p_coor))
		exit_cond = modify_map(p_coor, params, keycode, p);
	if (exit_cond == 100 && params->info->exit_m == 0)
	{
		e_coor = find_coordinates(params->map, 'E', params->info);
		params->map[e_coor[0]][e_coor[1]] = 'O';
		params->info->exit_m = 1;
		free(e_coor);
	}
	check_end(params, p_coor);
	return (0);
}
