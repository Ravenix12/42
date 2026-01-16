/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:29:29 by smariapp          #+#    #+#             */
/*   Updated: 2026/01/16 16:15:10 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	open_file(char **argv, int io, int argc)
{
	int	fd;

	if (ft_strncmp(argv[1], "here_doc", 9) != 0 && io == 2)
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strncmp(argv[1], "here_doc", 9) == 0 && io == 2)
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (io == 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = -1;
	return (fd);
}

void	process1_5(int read, int write, char *argv, char **envp)
{
	char	**args;
	char	*path;

	dup2(read, STDIN_FILENO);
	dup2(write, STDOUT_FILENO);
	close(read);
	if (argv && *argv)
	{
		args = ft_split(argv, ' ');
		path = path_constructor(args[0]);
		if (!path)
		{
			helper_free(args, argv, NULL, 0);
			exit(127);
		}
		execve(path, args, envp);
		helper_free(args, argv, NULL, 0);
		exit (1);
	}
	else
		write_for_me(STDOUT_FILENO, write);
	close(write);
	exit (1);
}

//This should replace process 1 for heredoc
void	heredoc_proc(char **argv, int read[2])
{
	char	*line;
	int		len;

	close(read[0]);
	len = ft_strlen(argv[2]);
	while (1)
	{
		write(2, "> ", 2);
		line = get_next_line(0, 0);
		if (ft_strncmp(line, argv[2], len) == 0 && line[len] == '\n')
			break ;
		write(read[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(read[1]);
	exit(0);
}
