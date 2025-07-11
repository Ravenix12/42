/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:03:10 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/24 20:03:09 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstd_fd(char *s, int fd, const char **str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[0] == '%' && s[1] == '%')
	{
		count += write(fd, "%%", 1);
		(*str)++;
		s += 2;
	}
	while (s[i] != '\0' && s[i] != '%')
	{
		count += write(fd, &s[i], 1);
		i++;
	}
	(*str) += count;
	return (count);
}
