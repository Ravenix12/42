/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:13:55 by smariapp          #+#    #+#             */
/*   Updated: 2026/01/14 20:07:40 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	pipes_inbtw(int read, char **argv, char **envp, int start)
{
	int	len;
	int	p[2];
	int	cpid;
	int	status;
	int	prev_fd;

	prev_fd = read;
	len = ft_arrlen(argv) - 1;
	while (start < len)
	{
		if (pipe(p) == -1)
			exit(1);
		cpid = fork();
		if (cpid == 0)
		{
			close(p[0]);
			process1_5(prev_fd, p[1], argv[start++], envp);
		}
		if (prev_fd != read)
			close(prev_fd);
		close(p[1]);
		prev_fd = p[0];
		waitpid(cpid, &status, 0);
	}
	return (prev_fd);
}

int	dwpipes_bonus(int fd1, int fd2, char **argv, char **envp)
{
	int	cpid;
	int	fd;
	int	p[2];
	int	status1;
	int	status2;

	status1 = 0;
	status2 = 0;
	pipe(p);
	cpid = fork();
	if (cpid == 0)
		process1(p, argv[2], envp, fd1);
	close(p[1]);
	waitpid(cpid, &status1, 0);
	fd = pipes_inbtw(p[0], argv, envp, 3);
	cpid = fork();
	if (cpid == 0)
		process2((int [2]){fd, -1}, argv[3], envp, fd2);
	waitpid(cpid, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (close(p[0]), close(p[1]), 1);
}

int	dwpipes_hd(int fd2, char **argv, char **envp)
{
	int	cpid;
	int	fd;
	int	p[2];
	int	status1;
	int	status2;

	status1 = 0;
	status2 = 0;
	pipe(p);
	cpid = fork();
	if (cpid == 0)
		heredoc_proc(argv, p);
	close(p[1]);
	waitpid(cpid, &status1, 0);
	fd = pipes_inbtw(p[0], argv, envp, 3);
	cpid = fork();
	if (cpid == 0)
		process2((int [2]){fd, -1}, argv[3], envp, fd2);
	waitpid(cpid, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (close(p[0]), close(p[1]), 1);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	ret;

	if (argc >= 5)
	{
		fd2 = open_file(argv, 2, argc);
		if (fd2 < 0)
			no_space_for_exit(argv[argc - 1], 1);
		if (ft_strncmp(argv[1], "here_doc", 9) != 0)
			fd1 = open_file(argv, 1, argc);
		else if (argc >= 6)
			return (close(fd2), dwpipes_hd(fd2, argv, envp));
		else
			no_space_for_exit("insuffient arguments", 1);
		if (fd1 < 0)
		{
			perror(argv[1]);
			fd1 = open("/dev/null", O_RDONLY | O_CREAT);
		}
		ret = dwpipes_bonus(fd1, fd2, argv, envp);
		return (close(fd1), close(fd2), ret);
	}
	no_space_for_exit("insuffient arguments", 1);
}
