/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:26 by smariapp          #+#    #+#             */
/*   Updated: 2025/09/06 22:16:08 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	gimme_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	return (fd);
}

void	check_file_type(char *file)
{
	int	len;

	len = ft_strlen(file);
	file += (len - 4);
	if (ft_strncmp(file, ".ber", 4) != 0)
	{
		write(2, "Error\nInvalid File Type\n", 23);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_p		*info;
	char	**map;

	if (argc != 2)
	{
		write(2, "Error\nInvalid Argument(s)\n", 26);
		exit(1);
	}
	check_file_type(argv[1]);
	fd = gimme_fd(argv[1]);
	info = check_invalid(fd);
	close(fd);
	fd = gimme_fd(argv[1]);
	map = solvable_entry(fd, info);
	close(fd);
	lib_entry(map, info);
	return (0);
}
