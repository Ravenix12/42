/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:45:24 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/24 20:03:24 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchari_fd(int c, int fd, const char **s)
{
	(*s) += 2;
	c = (unsigned char)c;
	write(fd, &c, 1);
	return (1);
}
