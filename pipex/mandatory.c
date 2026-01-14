/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:24:27 by smariapp          #+#    #+#             */
/*   Updated: 2026/01/14 21:19:18 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	helper_free(char **args, char *argv, char *path, int ret)
{
	free_arr(args);
	perror(argv);
	if (path != NULL)
		free(path);
	return (ret);
}

void	process1(int pipefds[2], char *argv, char **envp, int fd1)
{
	char	**args;
	char	*path;

	close(pipefds[0]);
	dup2(fd1, STDIN_FILENO);
	dup2(pipefds[1], STDOUT_FILENO);
	close(pipefds[1]);
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
		write_for_me(STDOUT_FILENO, fd1);
	close(fd1);
	exit (1);
}

void	process2(int pipefds[2], char *argv, char **envp, int fd2)
{
	char	**args;
	char	*path;

	close(pipefds[1]);
	dup2(pipefds[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(pipefds[0]);
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
		helper_free(args, argv, path, 0);
		exit(1);
	}
	else
		write_for_me(fd2, STDIN_FILENO);
	close(fd2);
	exit(1);
}

int	dwpipes(int fd1, int fd2, char **argv, char **envp)
{
	int		cpid1;
	int		cpid2;
	int		pipefds[2];
	int		status1;
	int		status2;

	status1 = 0;
	status2 = 0;
	pipe(pipefds);
	cpid1 = fork();
	if (cpid1 == 0)
		process1(pipefds, argv[2], envp, fd1);
	cpid2 = fork();
	if (cpid2 == 0)
		process2(pipefds, argv[3], envp, fd2);
	close(pipefds[0]);
	close(pipefds[1]);
	waitpid(cpid1, &status1, 0);
	waitpid(cpid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else
		return (1);
}
