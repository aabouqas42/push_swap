/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:31:41 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 23:59:18 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	unsigned_printf(unsigned int num)
{
	char	*str;
	int		len;

	if (num == 0)
		return (putchar_printf('0'));
	len = ft_numlen(num);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	str[len] = '\0';
	len--;
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
	free (str);
	return (len);
}
