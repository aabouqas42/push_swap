/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:02:46 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 23:52:44 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num *= (-1);
	}
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static int	ft_helper(char *str, int num, int len)
{
	while (num)
	{
		str[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	if (putstr_printf(str) == -1)
	{
		free (str);
		return (-1);
	}
	len = strlen_printf(str);
	free(str);
	return (len);
}

int	print_number_printf(int num)
{
	char	*str;
	int		len;

	if (num == 0)
		return (putchar_printf('0'));
	if (num == -2147483648)
		return (putstr_printf("-2147483648"));
	len = ft_numlen(num);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	if (num < 0)
	{
		str[0] = '-';
		num *= (-1);
	}
	str[len] = '\0';
	return (ft_helper(str, num, len - 1));
}
