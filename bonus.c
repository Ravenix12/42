/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:13:55 by smariapp          #+#    #+#             */
/*   Updated: 2025/12/31 19:49:42 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	process1_5(int read[2], int write[2], char *argv, char **envp)
{
	char	**args;
	char	*path;

	close(read[0]);
	close(write[1]);
	dup2(write[0], STDIN_FILENO);
	dup2(read[1], STDOUT_FILENO);
	close(read[1]);
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
		write_for_me(STDOUT_FILENO, write[0]);
	close(write[0]);
	exit (1);
}

int	dwpipes(int fd1, int fd2, char **argv, char **envp, int argc)
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

int	heredoc(char **argv, char **envp, int fd2)
{
	char	*line;
	int		read[2];
	int		write[2];
	
	
	line = get_next_line(STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	ret;

	if (argc >= 5)
	{
		fd2 = open_file(argv, 2);
		if (fd2 < 0)
			no_space_for_exit(argv[argc - 1], 1);
		if (ft_strncmp(argv[1], "here_doc", 9) != 0)
			fd1 = open_file(argv, 1);
		else
			break; //call here_doc
		if (fd1 < 0)
		{
			perror(argv[1]);
			fd1 = open("/dev/null", O_RDONLY | O_CREAT);
		}
		ret = dwpipes(fd1, fd2, argv, envp);
		return (close(fd1), close(fd2), ret);
	}
	else
		no_space_for_exit("insuffient arguments", 1);
}
