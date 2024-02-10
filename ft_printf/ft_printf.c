/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:38:18 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 23:57:04 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handler(va_list args, const char c)
{
	if (c == 's')
		return (putstr_printf (va_arg(args, char *)));
	if (c == 'c')
		return (putchar_printf (va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (print_number_printf(va_arg(args, int)));
	if (c == 'x')
		return (base_printf(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (base_printf(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (pointer_printf(va_arg(args, unsigned long)));
	if (c == 'u')
		return (unsigned_printf(va_arg(args, unsigned int)));
	if (c == '%')
		return (putchar_printf('%'));
	return (putchar_printf(c));
}

static int	print(const char *str, va_list args)
{
	int	got;
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
			{
				got = handler(args, *str++);
				if (got == -1)
					return (-1);
				len += got;
			}
		}
		else if (*str)
		{
			if (putchar_printf((int)*str++) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start (args, str);
	len = print(str, args);
	va_end(args);
	return (len);
}
