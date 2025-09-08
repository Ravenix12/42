/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:24:10 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 21:49:18 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	unsolvable_exit(char **map, char **dup, int *coor, t_p *info)
{
	free_arr(dup);
	free_arr(map);
	free(coor);
	free(info);
	write(2, "Error\nMap Unsolvable\n", 21);
	exit(1);
}

int	exit_reachable(char **map, int *E)
{
	int	y;
	int	x;

	y = E[0];
	x = E[1];
	if (map[y + 1][x] == 'F' || map[y + 1][x] == 'P')
		return (1);
	else if (map[y - 1][x] == 'F' || map[y - 1][x] == 'P')
		return (1);
	else if (map[y][x + 1] == 'F' || map[y][x + 1] == 'P')
		return (1);
	else if (map[y][x - 1] == 'F' || map[y][x - 1] == 'P')
		return (1);
	return (0);
}

void	check_solvable(char **dup, char **map, t_p *info, int fd)
{
	int	*e_coor;
	int	*c_coor;

	c_coor = find_coordinates(dup, 'C', info);
	if (c_coor != NULL)
	{
		close(fd);
		unsolvable_exit(map, dup, c_coor, info);
	}
	e_coor = find_coordinates(dup, 'E', info);
	if (!exit_reachable(dup, e_coor))
	{
		close(fd);
		unsolvable_exit(map, dup, c_coor, info);
	}
	free_arr(dup);
	free(e_coor);
}

char	**solvable_entry(int fd, t_p *info)
{
	char	**map;
	char	**dup;
	int		*p_coor;

	map = save_map(fd, info);
	p_coor = find_coordinates(map, 'P', info);
	dup = duplicate_map(map, info);
	fill_horizontal(dup, p_coor, info);
	fill_vertical(dup, p_coor, info);
	free(p_coor);
	check_solvable(dup, map, info, fd);
	return (map);
}
