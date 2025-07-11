/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:35:05 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/25 16:33:13 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digits_ul(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= base;
		count += 1;
	}
	return (count);
}

int	ft_puthexl_fd(unsigned int n, int fd)
{
	int				digits;
	unsigned int	num;
	char			temp[1];
	unsigned int	divisor;
	int				count;

	digits = ft_digits(n, 16);
	count = 0;
	while (digits > 0)
	{
		divisor = ft_pow(16, digits - 1);
		num = n / divisor;
		temp[0] = "0123456789abcdef"[num];
		count += write (fd, temp, 1);
		n %= divisor;
		digits --;
	}
	return (count);
}

int	ft_puthexu_fd(unsigned int n, int fd)
{
	int				digits;
	unsigned int	num;
	char			temp[1];
	unsigned int	divisor;
	int				count;

	digits = ft_digits(n, 16);
	count = 0;
	while (digits > 0)
	{
		divisor = ft_pow(16, digits - 1);
		num = n / divisor;
		temp[0] = "0123456789ABCDEF"[num];
		count += write (fd, temp, 1);
		n %= divisor;
		digits --;
	}
	return (count);
}

int	ft_puthexul_fd(unsigned long n, int fd, const char **s)
{
	unsigned int	digits;
	unsigned long	num;
	char			temp[1];
	unsigned long	divisor;
	int				count;

	(*s) += 2;
	if (n == 0)
		return (write(fd, "(nil)", 5));
	digits = ft_digits_ul(n, 16);
	count = write(fd, "0x", 2);
	while (digits > 0)
	{
		divisor = ft_pow_ul(16, digits - 1);
		num = n / divisor;
		temp[0] = "0123456789abcdef"[num];
		count += write (fd, temp, 1);
		n %= divisor;
		digits --;
	}
	return (count);
}

int	ft_puthex_fd(unsigned int n, int fd, char c, const char **s)
{
	(*s) += 2;
	if (c == 'p' || c == 'x')
	{
		return (ft_puthexl_fd(n, fd));
	}
	else if (c == 'X')
		return (ft_puthexu_fd(n, fd));
	return (0);
}
