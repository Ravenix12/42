/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pics_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:13:29 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 17:43:26 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_imgarr(void **arr, t_data *data)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			mlx_destroy_image(data->mlx, arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_display(t_data *data, t_dis *images)
{
	if (images->player)
		free_imgarr(images->player, data);
	if (images->collectible)
		mlx_destroy_image(data->mlx, images->collectible);
	if (images->wall)
		free_imgarr(images->wall, data);
	if (images->emp)
		mlx_destroy_image(data->mlx, images->emp);
	if (images->exit)
		free_imgarr(images->exit, data);
	if (images->enemy)
		free_imgarr(images->enemy, data);
	if (images)
		free(images);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	malloc_fail(char **map, t_p *info, t_data *data, t_dis *images)
{
	free_display(data, images);
	malloc_exit(map, info);
}

int	set_image(void **location, char *path, t_data *data, int flag)
{
	int		x;

	x = 64;
	if (!flag)
	{
		*location = mlx_xpm_file_to_image(data->mlx, path, &x, &x);
		if (!*location)
			flag = 1;
	}
	return (flag);
}

void	init_pics(t_dis	*image, char **map, t_p *info, t_data *data)
{
	int		flag;

	flag = 0;
	flag = set_image(&image->emp, "pics/bg.xpm", data, flag);
	flag = set_image(&image->collectible, "pics/c.xpm", data, flag);
	image->player = ft_calloc(3, sizeof(void *));
	image->exit = ft_calloc(3, sizeof(void *));
	image->wall = ft_calloc(4, sizeof(void *));
	image->enemy = ft_calloc(4, sizeof(void *));
	if (!image->player || !image->wall || !image->exit || !image->enemy
		|| flag == 1)
		malloc_fail(map, info, data, image);
	flag = set_image(&image->player[0], "pics/p.xpm", data, flag);
	flag = set_image(&image->player[1], "pics/p1.xpm", data, flag);
	flag = set_image(&image->wall[0], "pics/ceil.xpm", data, flag);
	flag = set_image(&image->wall[1], "pics/floor1.xpm", data, flag);
	flag = set_image(&image->wall[2], "pics/wall.xpm", data, flag);
	flag = set_image(&image->exit[0], "pics/exit-01.xpm", data, flag);
	flag = set_image(&image->exit[1], "pics/exit-11.xpm", data, flag);
	flag = set_image(&image->enemy[0], "pics/enemy1.xpm", data, flag);
	flag = set_image(&image->enemy[1], "pics/enemy3.xpm", data, flag);
	flag = set_image(&image->enemy[2], "pics/enemy2.xpm", data, flag);
	if (flag)
		malloc_fail(map, info, data, image);
}
