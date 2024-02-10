/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:04:31 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/09 22:02:04 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_position(t_stack *stack, int number)
{
	t_stack	*node;
	int		pos;

	node = stack;
	pos = 1;
	while (node)
	{
		if (node->number == number)
			return (pos);
		node = node->next;
		pos++;
	}
	return (0);
}
