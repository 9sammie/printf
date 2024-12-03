/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:34:26 by maballet          #+#    #+#             */
/*   Updated: 2024/12/02 19:02:13 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *s, ...);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_hexa_low(unsigned int n);
int	ft_hexa_up(unsigned int n);
int	ft_unsigned(unsigned int n);

#endif