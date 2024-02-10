/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:29:27 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 23:58:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	baselen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static int	ft_helper(char *str, char *base, unsigned int num, int len)
{
	while (num)
	{
		str[len] = base[num % 16];
		num /= 16;
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

int	base_printf(unsigned int num, char *base)
{
	char	*str;
	int		len;

	if (num == 0)
		return (putchar_printf('0'));
	len = baselen(num);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	str[len] = '\0';
	return (ft_helper(str, base, num, len - 1));
}
