/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:34:56 by smariapp          #+#    #+#             */
/*   Updated: 2025/06/07 17:01:10 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strcopy(char *src, char *dst, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_strlen(const char *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++ ;
	return (len);
}

int	ft_strchrm(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

t_fdnode	*get_fdnode(int fd, t_fdnode **head)
{
	t_fdnode	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	curr = malloc(sizeof(t_fdnode));
	if (!curr)
		return (NULL);
	curr->fd = fd;
	curr->rem = NULL;
	curr->next = *head;
	*head = curr;
	return (curr);
}

void	free_fdnode(int fd, t_fdnode **head)
{
	t_fdnode	*curr;
	t_fdnode	*prev;

	curr = *head;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*head = curr->next;
			free(curr->rem);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
