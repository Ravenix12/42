/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:52:55 by smariapp          #+#    #+#             */
/*   Updated: 2025/10/02 17:41:39 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	no_space_for_exit(char *statement, int status)
{
	perror(statement);
	exit(status);
}

void	write_for_me(int writefd, int readfd)
{
	size_t	b_read;
	char	buffer[1024];

	b_read = read(readfd, buffer, sizeof(buffer));
	while (b_read > 0)
	{
		write(writefd, buffer, b_read);
		b_read = read(readfd, buffer, sizeof(buffer));
	}
}

char	**get_paths(void)
{
	char	*path;
	char	**paths;
	int		len;

	len = ft_strlen("/home/smariapp/bin/:/home/smariapp/bin/:/usr\
	/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/bin/:/usr\
	/games/:/usr/local/games/:/snap/bin/");
	path = malloc(len + 1);
	ft_strlcpy(path, "/home/smariapp/bin/:/home/smariapp/bin/:/usr\
	/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/bin/:/usr\
	/games/:/usr/local/games/:/snap/bin/", len);
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

void	free_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp != NULL)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}

char	*path_constructor(char *arr)
{
	char	**paths;
	char	*join;
	int		i;

	i = 0;
	if (ft_strchr(arr, '/') != NULL && access(arr, F_OK) == 0)
		return (ft_strdup(arr));
	else if (ft_strchr(arr, '/') != NULL)
		return (NULL);
	paths = get_paths();
	while (paths[i])
	{
		join = ft_strjoin(paths[i], arr);
		if (access (join, F_OK) == 0)
		{
			free_arr(paths);
			return (join);
		}
		free(join);
		i++;
	}
	free_arr(paths);
	return (NULL);
}
