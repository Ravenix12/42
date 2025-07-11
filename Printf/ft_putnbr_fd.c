/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:52 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/24 20:03:14 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(int n, int fd)
{
	int		digits;
	int		num;
	char	temp[1];
	int		divisor;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	digits = ft_digits(n, 10);
	while (digits > 0)
	{
		divisor = ft_pow(10, digits - 1);
		num = n / divisor;
		temp[0] = num + '0';
		count += write (fd, temp, 1);
		n %= divisor;
		digits --;
	}
	return (count);
}

int	ft_putnbri_fd(int n, int fd, const char **s)
{
	(*s) += 2;
	return (helper(n, fd));
}
