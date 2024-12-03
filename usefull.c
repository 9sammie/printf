/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:39:34 by maballet          #+#    #+#             */
/*   Updated: 2024/12/02 19:10:34 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
	{
		write(2, "error", 6);
		return (1);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	num;
	char	c;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_hexa_low(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
		len += ft_hexa_low(n / 16);
	c = "0123456789abcdef"[n % 16];
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_hexa_up(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
		len += ft_hexa_up(n / 16);
	c = "0123456789ABCDEF"[n % 16];
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_unsigned(unsigned int n)
{
	unsigned int	num;
	char			c;
	int				len;

	num = n;
	len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
