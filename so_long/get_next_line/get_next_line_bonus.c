/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:35:00 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/29 15:46:00 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_allocate_rem(char *rem)
{
	size_t	length;
	size_t	i;
	char	*ptr;

	if (rem == NULL || *rem == '\0')
		return (NULL);
	length = ft_strlen(rem);
	ptr = malloc(length + 1);
	i = 0;
	while (i < length)
	{
		ptr[i] = rem[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_alloc(char *line, char *buf, int ix)
{
	char	*new_line;
	size_t	len;

	len = ft_strlen(line);
	new_line = malloc(len + ix + 1);
	if (!new_line)
		return (NULL);
	if (line)
	{
		ft_strcopy(line, new_line, len);
		free(line);
	}
	ft_strcopy(buf, &new_line[len], ix);
	return (new_line);
}

char	*ft_body(int fd, char **rem, char *buf, char *line)
{
	int		ix;
	ssize_t	n;

	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		ix = ft_strchrm(buf, '\n');
		if (ix >= 0)
		{
			free(*rem);
			line = ft_alloc(line, buf, ix + 1);
			*rem = ft_allocate_rem(&buf[ix + 1]);
			break ;
		}
		line = ft_alloc(line, buf, n);
		n = read(fd, buf, BUFFER_SIZE);
	}
	if (n <= 0)
		free(*rem);
	if (n <= 0)
		*rem = NULL;
	return (line);
}

char	*ft_line(t_fdnode *n, int fd, t_fdnode **fd_lst, char *buf)
{
	char	*line;
	char	*new_rem;
	int		ix;

	ix = ft_strchrm(n->rem, '\n');
	if (ix >= 0)
	{
		line = ft_alloc(NULL, n->rem, ix + 1);
		new_rem = ft_allocate_rem(&n->rem[ix + 1]);
		free(n->rem);
		n->rem = new_rem;
		free(buf);
		return (line);
	}
	line = ft_body(fd, &n->rem, buf, ft_allocate_rem(n->rem));
	if (!line)
		free_fdnode(fd, fd_lst);
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fdnode	*fd_list;
	t_fdnode		*node;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_fdnode(fd, &fd_list);
	if (!node)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	return (ft_line(node, fd, &fd_list, buf));
}
