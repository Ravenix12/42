/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:05:14 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/04 20:00:44 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	assign(char **map, int *coor, char c, t_p *info)
{
	int	x;
	int	y;

	y = coor[0];
	x = coor[1];
	map[y][x] = 'F';
	if (c == 'H')
		fill_horizontal(map, coor, info);
	else if (c == 'V')
		fill_vertical(map, coor, info);
}

void	fill_vertical(char **map, int *coor, t_p *info)
{
	int	i;
	int	x;
	int	y;

	y = coor[0];
	x = coor[1];
	i = y - 1;
	while (i > 0 && map[i][x] != '1' && map[i][x] != 'E')
	{
		if (map[i][x] != 'F' && map[i][x] != 'P')
			assign(map, (int []){i, x}, 'H', info);
		i--;
	}
	i = y + 1;
	while (i < info->lines && map[i][x] != '1' && map[i][x] != 'E')
	{
		if (map[i][x] != 'F' && map[i][x] != 'P')
			assign(map, (int []){i, x}, 'H', info);
		i++;
	}
}

void	fill_horizontal(char **map, int *coor, t_p *info)
{
	int	i;
	int	x;
	int	y;

	y = coor[0];
	x = coor[1];
	i = x - 1;
	while (i > 0 && map[y][i] != '1' && map[y][i] != 'E')
	{
		if (map[y][i] != 'F' && map[y][i] != 'P')
			assign(map, (int []){y, i}, 'V', info);
		i--;
	}
	i = x + 1;
	while (i < info->length && map[y][i] != '1' && map[y][i] != 'E')
	{
		if (map[y][i] != 'F' && map[y][i] != 'P')
			assign(map, (int []){y, i}, 'V', info);
		i++;
	}
}
