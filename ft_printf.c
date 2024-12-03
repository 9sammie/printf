/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:08:25 by maballet          #+#    #+#             */
/*   Updated: 2024/12/03 11:53:41 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar(char c);
static int	ft_check(va_list ap, int *i, const char *s);
static int	ft_hexa_ptr(unsigned long n);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\n')
			len++;
		if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		if (s[i] == '%')
		{
			len += ft_check(ap, &i, s);
			i++;
		}
		else
			len = ft_putchar(s[i]) + len;
		i++;
	}
	va_end(ap);
	return (len);
}

static int	ft_ptr(void *ptr)
{
	unsigned long	adr;
	int				len;

	len = 0;
	adr = (unsigned long)ptr;
	write(1, "0x", 2);
	len += 2;
	len += ft_hexa_ptr(adr);
	return (len);
}

static int	ft_hexa_ptr(unsigned long n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
		len += ft_hexa_ptr(n / 16);
	c = "0123456789abcdef"[n % 16];
	write(1, &c, 1);
	len++;
	return (len);
}

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_check(va_list ap, int *i, const char *s)
{
	int	len;

	len = 0;
	if (s[*i + 1] == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (s[*i + 1] == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (s[*i + 1] == 'p')
		ft_ptr(va_arg(ap, void *));
	else if (s[*i + 1] == 'd' || s[*i + 1] == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (s[*i + 1] == 'u')
		ft_unsigned(va_arg(ap, unsigned int));
	else if (s[*i + 1] == 'x')
		len += ft_hexa_low(va_arg(ap, int));
	else if (s[*i + 1] == 'X')
		len += ft_hexa_up(va_arg(ap, int));
	else if (s[*i + 1] == '%')
		len = len;
	else
		len += ft_putchar(s[*i]);
		len += ft_putchar(s[*i + 1]);
	return (len);
}

// int main(void)
// {
// 	int	a;
// 	int	b;

// 	a = printf("%%%%%%", 6);
// 	b = ft_printf("%%%%%%", 6);
// 	write(1, "\n", 1);
// 	printf("\na = %d\nb = %d", a, b);
// 	return (0);
// }
