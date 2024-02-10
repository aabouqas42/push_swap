/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:11:54 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 23:58:44 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_printf(char *str)
{
	if (!str)
		return (write (1, "(null)", 6));
	return (write (1, str, strlen_printf(str)));
}
