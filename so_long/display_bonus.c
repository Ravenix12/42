/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:09:53 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 21:42:47 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display_cf(int i, int x, t_par *params, int shift)
{
	int	j;
	int	length;

	j = 0;
	length = params->info->dx;
	while (i == 0 && j < length)
	{
		mlx_put_image_to_window(params->data->mlx, params->data->win,
			params->display->wall[0], j * 64, (i - shift) * 64);
		j++;
	}
	if (j == length)
		return ;
	while (i == params->info->lines - 1 && j < length)
	{
		mlx_put_image_to_window(params->data->mlx, params->data->win,
			params->display->wall[1], j * 64, (i - shift) * 64);
		j++;
	}
	if (x == 0)
		mlx_put_image_to_window(params->data->mlx, params->data->win,
			params->display->wall[2], 0, (i - shift) * 64);
	if (x + length == params->info->length)
		mlx_put_image_to_window(params->data->mlx, params->data->win,
			params->display->wall[2], (j - 1) * 64, (i - shift) * 64);
}

static int	get_enemy_anim(void)
{
	static int	i;

	if (i >= 2)
		i = 0;
	else
		i++;
	return (i);
}

void	display_ncf(int i, int j, t_par *params, int *tl)
{
	void	*img;

	if (i == 0 || i == params->info->lines - 1)
		return ;
	if (params->map[i][j] == '0')
		img = params->display->emp;
	if (params->map[i][j] == '1')
		img = params->display->wall[2];
	if (params->map[i][j] == 'C')
		img = params->display->collectible;
	if (params->map[i][j] == 'E')
		img = params->display->exit[0];
	if (params->map[i][j] == 'O')
		img = params->display->exit[1];
	if (params->map[i][j] == 'L')
		img = params->display->player[0];
	if (params->map[i][j] == 'P')
		img = params->display->player[1];
	if (params->map[i][j] == 'X')
		img = params->display->enemy[get_enemy_anim()];
	mlx_put_image_to_window(params->data->mlx, params->data->win,
		img, ((j - tl[1]) * 64), ((i - tl[0]) * 64));
}

int	*find_top_left(t_par *params)
{
	int	width;
	int	height;
	int	*coor;
	int	*tl;

	tl = malloc(2 * sizeof(int));
	coor = find_coordinates(params->map, 'P', params->info);
	if (!coor)
		coor = find_coordinates(params->map, 'L', params->info);
	width = params->info->length;
	height = params->info->lines;
	tl[1] = coor[1] - params->info->dx / 2;
	if (tl[1] < 0 || width == params->info->dx)
		tl[1] = 0;
	else if (tl[1] > width - params->info->dx)
		tl[1] = width - params->info->dx;
	tl[0] = coor[0] - params->info->dy / 2;
	if (tl[0] < 0 || height == params->info->dy)
		tl[0] = 0;
	else if (tl[0] > height - params->info->dy)
		tl[0] = height - params->info->dy;
	free(coor);
	return (tl);
}

int	display_screen(t_par *params)
{
	int		i;
	int		j;
	int		y;
	int		x;
	int		*tl;

	tl = find_top_left(params);
	y = params->info->dy + tl[0];
	x = params->info->dx + tl[1];
	i = tl[0] - 1;
	while (++i < y)
	{
		j = tl[1];
		if (i == 0 || i == params->info->lines - 1)
			display_cf(i, j, params, tl[0]);
		while (j < x)
			display_ncf(i, j++, params, tl);
	}
	put_counter(params);
	usleep(100000);
	return (free(tl), 1);
}
